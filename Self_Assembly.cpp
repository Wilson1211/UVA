//

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
#define imp(i, j) insert(make_pair(i, j)) 
#define X first
#define Y second

set<string> ss;

map<string, int> dic;
set<int> exist;
class node{
public:
    node(){}
    vector<node> next;
};
node Node[53];

int existed[53];
bool process_dfs(int i){
    if(existed[i]==1){
        return 1;
    }
    int sz = (Node[i].next).size();
    bool flag = 0;
    FOR(j, 0, sz){
        flag = process_dfs((Node[i].next)[j]);
        if(flag == 1) return 1;
    }
    return 0;
}

int main() {
    int K;
    string str;
    string D="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    FOR(i, 0, 26){
        string tmp;
        tmp = D[i]+'+';
        dic.insert(make_pair(tmp, i));
        tmp = D[i]+'-';
        dic.insert(make_pair(tmp, i+26));
    }
    while(cin>>K){
        FOR(i, 0, K){
            cin>>str;
            string tmp;
            int num[4];
            int k = 0;
            for(int j=0;j<8;j+=2){
                tmp = str.substr(j, 2);
                if(tmp!="00") {
                    exist.insert(dic[tmp]);
                    num[k++] = dic[tmp];
                }
            }
            FOR(j, 0, k){
                FOR(l, 0, k){
                    if(j!=l){
                        (Node[num[j]].next).eb(num[l]);
                    }
                }
            }
        }
        bool flag=0;
        FOR(i, 0, 52){
            if(exist.find(i)!=exist.end()){
                memset(existed, 0, 53*sizeof(int));
                flag = process_dfs(i);
                if(flag==1) break;
            }
        }
        if(flag) cout<<"unbounded\n";
        else cout<<"bounded\n";
    }
}