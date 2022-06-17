//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=481


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FOR(i,A,B) for(int i=A;i<B;++i)
#define FOR1(i,A,B) for(int i=A;i<=B;++i)
#define SZ(i) int(i.size())
#define eb emplace_back
#define pb pop_back
#define ALL(i) i.begin(),i.end()
#define X first
#define Y second

int main() {

    int t;
    int n;
    int tp;
    while((cin>>t) && t){ // t teams
        vector<vector<int>> teams(t, vector<int>());
        FOR(i, 0, t){
            cin >> n;
            FOR(j, 0, n){
                cin >> tp;
                teams[i].eb(tmp);
            }
        }
        string cmd;
        queue<int> Que;
        queue<int> Que2;
        while((cin >> cmd) && (cmd != "STOP")){
            if(cmd[0]=='E'){

            }else{
                Que.pop();
            }
        }
    }


    return 0;
}