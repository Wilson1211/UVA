#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<string, vector<string>> Pair;



map<string, vector<string>> library;

map<string, bool> unshelve;

void print_library(map<string, vector<string>> *lib){
    map<string, vector<string>>::iterator it;
    vector<string>::iterator itv;

    for(it=(*lib).begin();it!=(*lib).end();it++){
        cout<<it->first;
        itv = (it->second).begin();
        for(;itv!=(it->second).end();itv++) {
            cout<<" "<<(*itv);
        }
        cout<<endl;
    }
}

void print_vec(vector<Pair> *vec){
    vector<Pair>::iterator itv;
    string title;
    vector<string> *ptr;
    for(itv = (*vec).begin();itv != (*vec).end();itv++){
        title = (*itv).first;
        *ptr = (*itv).second;
        cout<<title;
        for(int i=0;i<(*ptr).size();i++){
            cout<<" "<<(*ptr)[i];
        }
        cout<<endl;
    }
}

void process_str(string &ss) {
    int ptr, ptr_and, ptr_and2, ptr_by;
    string title, author;
    
    ptr_by = ss.find("by");
    title = ss.substr(0, ptr_by-1);
    library[title] = vector<string>();

    ptr_by+=2;
    while(ss[ptr_by]==' ') ptr_by++; 

    ptr_and = ss.find("and");
    if(ptr_and == string::npos) { // only one author
        author = ss.substr(ptr_by);
        library[title].push_back(author);
    }else{
        author = ss.substr(ptr_by, ptr_and-ptr_by-1);
        library[title].push_back(author);
    }
    
    //if(ptr_and != string::npos) author = ss.substr(ptr_by, ptr_and)
    while(ptr_and != string::npos){
        ptr_and +=3;
        while(ss[ptr_and] == ' ') ptr_and++; // author start from here

        ptr_and2 = ss.find(" and", ptr_and+1); //multiple authors
        if(ptr_and2 != string::npos){
            author = ss.substr(ptr_and, ptr_and2-ptr_and);
            library[title].push_back(author);
            ptr_and2 += 4;
            ptr_and = ptr_and2;
            ptr_and = ss.find("and", ptr_and);
            if(ptr_and == string::npos) {
                author = ss.substr(ptr_and2);
                library[title].push_back(author);
                break;
            }
        }else{
            author = ss.substr(ptr_and); // finish
            library[title].push_back(author);
            break;
        }
    }

}

void process_unshelve(string &ss){
    int i;
    string order;
    string book;
    order = ss.substr(0, 6);
    book = ss.substr(7);

    if(order == "BORROW"){
        unshelve[book] = 0;
    }else{
        unshelve[book] = 1;
    }
    

}

bool cmp(Pair &a, Pair &b){

    int num;
    int large; // -1 0 1 -> a.size, equal, b.size
    vector<string> *ptr_f, *ptr_s;

    *ptr_f = a.second;
    *ptr_s = b.second;
    
    if((*ptr_f).size() > (*ptr_s).size()){
        large = -1;
        num = (*ptr_s).size();
    }else if((*ptr_f).size() < (*ptr_s).size()){
        large = 1;
        num = (*ptr_f).size();
    }else{
        large = 0;
        num = (*ptr_f).size();
    }

    for(int i=0;i<num;i++) {
        if((*ptr_f)[i] < (*ptr_s)[i]){ return -1;}
        else if((*ptr_f)[i] > (*ptr_s)[i]) {return 1;}
    }

    if(large == -1) return 1;
    else return -1;

}

int main() {

    map<string, vector<string>>::iterator it_lib;
    map<string, bool>::iterator it_unslv;

    vector<Pair> vec;
    string input;


    while(getline(cin, input) && input != "END") {
        //cout<<"input: "<<input<<endl;
        process_str(input);
    }

    //print_library(&library);

    while(getline(cin, input) && input != "SHELVE") {
        process_unshelve(input);
    }

    //sort(library.begin(), library.end(), cmp);
    for(it_lib = library.begin();it_lib != library.end();it_lib++){
        vec.push_back(*it_lib);
    }
    sort(vec.begin(), vec.end(), cmp);

    print_vec(&vec);

    string book, pre_book;
    for(it_unslv = unshelve.begin();it_unslv!=unshelve.end();it_unslv++){
        //cout<<"in cout\n";
        if((*it_unslv).second){
            it_lib = library.find((*it_unslv).first);
            book = (*it_lib).first;
            if(it_lib == library.begin()){
                cout<<"Put "<<book<<" first"<<endl;
            }else{
                cout<<"Put "<<book<<" after ";
                --it_lib;
                pre_book = (*it_lib).first;
                cout<<pre_book<<endl;
            }
            
        }
    }
    

}