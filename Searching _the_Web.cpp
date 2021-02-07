#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define pair<int, int> Pair

map<string, Pair> web;

vector<vector<string>> article;


void check_term() {

}

void insert_web(const string ss) {
    string term;
    int begin, end;
    begin = end = 0;
    int i = 0;
    while(i <ss.length()){
        if(!isalpha(ss[i])){

        }

        i++;
    }
}


int main(){

    int i,j , k;
    int N;
    string article_str;
    vector<string> *str_ptr;
    cin >> N;
    
    cin.ignore();

    for(i=0;i<N;i++){
        
        getline(cin, article_str);
        if(article_str != "**********"){
            article[i].push_back(article_str);
        }
        
    }

    for(i=0;i<N;i++){
        str_ptr = &article[i];


        for(j=0;j<(*str_ptr).size();j++){
            if(!   str_ptr[j] 
        }


    }





    return 0;
}