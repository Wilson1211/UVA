//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4472
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOR1(i,a,b) for(int i=a;i<=b;++i)
#define INVFOR(i,a,b) for(int i=a;i>b;--i)
#define INVFOR1(i,a,b) for(int i=a;i>=b;--i)
#define SZ(i) int(i.size())
#define eb emplace_back
#define pb pop_back
#define ALL(i) i.begin(),i.end()
#define X first
#define Y second

vector<vector<pii>> bucket;
vector<vector<string>> paragraph;
map<string, set<pii> > dictionary;

void CMD(){

    int N;
    cin >> N;
    string cmd, keyword, keyword2;
    vector<pii> ans;
    vector<pii> tmp1;
    vector<int> tmp2;
    cin.ignore();
    FOR(z, 0, N){
        getline(cin, cmd);
        size_t first, second;
        first = cmd.find(' ');
        second = cmd.find(' ', first+1);
        //cout<<"first: "<<first<<" second: "<<second<<endl;
        if(first != string::npos &&(second==string::npos)){ // output paragraph without keyword
            int doc[100]={}; // paragraph
            keyword = cmd.substr(first+1);
            int para_sz = paragraph.size();
            cout<<"para_sz: "<<para_sz<<endl;
            set<pii> *ptr = &(dictionary[keyword]);
            for(set<pii>::iterator it = dictionary[keyword].begin(); it!=dictionary[keyword].end(); it++){
                doc[(*it).first]=1;
                cout<<"it: "<<(*it).first<<" "<<(*it).second<<endl;
            }
            FOR(i, 0, para_sz){
                vector<string> str;
                if(doc[i]==0){
                    str = paragraph[i];
                    FOR(j, 0, str.size()){
                        cout<<str[j]<<endl;
                    }    
                    cout<<"---------\n";
                }
            }
        }else{
            set<pii>::iterator ptr1, ptr2;
            keyword = cmd.substr(0, first);
            ptr1 = (dictionary[keyword]).begin();
            // cout<<"ptr1 size: "<<(*ptr1).size()<<endl;
            // cout<<"ptr1.first: "<<(*ptr1)[0].first<<" ptr2.second: "<<(*ptr2)[0].second<<endl;
            set<pii>::iterator found;
            if(first != string::npos){ // union / or
                //second = cmd.find(' ', first+1);
                string command;
                if(second != string::npos){
                    keyword2 = cmd.substr(second+1);
                    command = cmd.substr(first+1, second-first-1);
                    ptr2 = (dictionary[keyword2]).begin();
                }
                if(command[0]=='A'){ // union
                    // find 
                    // FOR(i, 0, dictionary[keyword2].size()){
                    //     found = find((dictionary[keyword]).begin(), (dictionary[keyword]).end(), (*ptr2));
                    //     if(found != (dictionary[keyword]).end()){
                    //         cout<<paragraph[(*found).first][(*found).second]<<endl;
                    //         //cout<<paragraph[(*ptr1)[found-(*ptr1).begin()].first][(*ptr1)[found-(*ptr1).begin()].second]<<endl;
                    //         cout<<"---------\n";
                    //     }
                    //     ptr2++;
                    // }

                    map<int, vector<int>> k1, ans;
                    ptr1 = dictionary[keyword].begin();
                    FOR(i, 0, dictionary[keyword].size()){
                        if(k1.find((*ptr1).first) != k1.end()){
                            k1[(*ptr1).first].eb((*ptr1).second);
                        }else{
                            vector<int> tmp;
                            tmp.eb((*ptr1).second);
                            k1.insert(make_pair((*ptr1).first, tmp));
                        }
                        ptr1++;
                    }

                    ptr2 = dictionary[keyword2].begin();
                    FOR(i, 0, dictionary[keyword2].size()){
                        int tmp = (*ptr2).first;
                        if(k1.find(tmp)!=k1.end()){
                            cout<<"tmp: "<<tmp<<endl;
                            if(ans.find(tmp)==ans.end()) {
                                vector<int> ttmp(k1[tmp]);
                                ans.insert(make_pair(tmp, ttmp));
                            }
                            vector<int>::iterator itt;
                            itt = find(ans[tmp].begin(), ans[tmp].end(), (*ptr2).second);
                            if(itt == ans[tmp].end()) ans[tmp].eb((*ptr2).second);
                        }
                        ptr2++;
                    }
                    FOR(i, 0, ans.size()) sort(ans[i].begin(), ans[i].end());
                    for(map<int, vector<int>>::iterator itt=ans.begin();itt!=ans.end();itt++){
                        FOR(i, 0, ((*itt).second).size()){
                            cout<<paragraph[(*itt).first][((*itt).second)[i]]<<endl;
                        }
                    }
                    cout<<"---------\n";
                }else{ // or
                    set<pii> tmp(dictionary[keyword]);
                    found = dictionary[keyword2].begin();
                    FOR(i, 0, (dictionary[keyword2]).size()){
                        tmp.insert((*found));
                        found++;
                    }
                    //sort(tmp.begin(), tmp.end())
                    found = tmp.begin();
                    FOR(i, 0, tmp.size()){
                        cout<<paragraph[(*found).first][(*found).second]<<endl;
                        cout<<"---------\n";
                        found++;
                    }
                }
            }else{ // cmd is keyword
                found = dictionary[keyword].begin();
                FOR(i, 0, (dictionary[keyword]).size()){
                    cout<<paragraph[(*found).first][(*found).second]<<endl;
                    cout<<"---------\n";
                    found++;
                }
            }
        }
        cout<<"==========\n";
    }



}


int main() {
    int N;
    string str;
    cin >> N;
    cin.ignore();
    FOR(i, 0, N){
        paragraph.eb(vector<string>());
        while(getline(cin, str)&&(str!="**********")){
            paragraph[i].eb(str);
        }
    }
    cout<<"finish first input\n";
    FOR(i, 0, N){ // paragraph
        int sz = paragraph[i].size();
        FOR(j, 0, sz){ // line
            str = paragraph[i][j];
            size_t pre_start=0, start=0;
            string tmp_str;
            while(start<str.length()){
                start = str.find(' ', pre_start);
                if(start != string::npos){
                    tmp_str = str.substr(pre_start, start-pre_start);
                }else{// deal with last word in a line
                    tmp_str = str.substr(pre_start);
                }
                FOR(k, 0, tmp_str.size()){
                    if(!isalnum(tmp_str[k])){
                        start = pre_start+k;
                        tmp_str = str.substr(pre_start, start-pre_start);
                        break;
                    }
                    tmp_str[k] = tolower(tmp_str[k]);
                }

        // find string in map
                if(dictionary.find(tmp_str)!=dictionary.end()){
                    set<pii> *tt = &(dictionary[tmp_str]);
                    (*tt).insert(make_pair(i, j));
                }else{
                    set<pii> tt;
                    tt.insert(make_pair(i, j));
                    dictionary.insert(make_pair(tmp_str, tt));
                }
                

                pre_start = start+1;
            }
            
        }
    }

// command

    // map<string, set<pii> >::iterator it;
    // cout<<"dictionary size: "<<dictionary.size()<<endl;
    // for(it=dictionary.begin();it!=dictionary.end();it++){
    //     cout<<(*it).first<<" "<<((*it).second).size()<<endl;
    // }

    CMD();

    return 0;
}