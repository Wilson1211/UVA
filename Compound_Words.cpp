#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {

/*
    char p[] = "abcdefghijklmnopqrstuvwxyz";
    map<char, vector<string>> words;
    map<char, vector<string>>::iterator it;

    for(int i=0;i<strlen(p);i++){
        words.insert()
    }
*/

    map<char, vector<string> > words;
    map<char, vector<string> >::iterator it;
    set<string> pound;
    set<string>::iterator itp;
    set<char> prefix_set;
    string input;
    
    int i;
    while(getline(cin,input)&&input !=""){


        it = words.find(input[0]);
        if(it != words.end()){ // found
            (it->second).push_back(input);
        }else{
            //words.push_back(input[0]);
            words[input[0]] = vector<string>();
            words[input[0]].push_back(input);
            prefix_set.insert(input[0]);
        }
        pound.insert(input);

    }

    string prefix, postfix;
    vector<string>::iterator itv, itv2; 
    int length;
    //string strtmp;
    //for(int i=0;i<words.size();i++){
    for(it=words.begin();it!=words.end();it++){
        //itv = words[prefix_set[i]].second;
        //cout<<words[prefix_set['a'] ].second<<endl;
        //itp = prefix_set.begin();
        //cout<<*(++itp);
        itv = (it->second).begin(); // itv points to map's vector begin
        
        //vector<string>::iterator itv = it->; 
        for(;itv!=(it->second).end();itv++){ // vector size
            itv2 = (it->second).begin();
            for(;itv2<itv;itv2++){
                length = (*itv2).length();
                prefix = (*itv).substr(0, length);
                if(prefix == (*itv2)){
                    //length = (*itv2).length();
                    postfix = (*itv).substr(length);
                    
                    itp = pound.find(postfix);
                    if(itp != pound.end()){
                        cout<<(*itv)<<endl;
                    }
                }
                
            }
        }
    }

    return 0;
}