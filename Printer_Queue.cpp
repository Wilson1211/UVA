//https://codeforces.com/contest/1616/problem/E
#include <bits/stdc++.h>

using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define INVFOR(i, a, b) for(int i=a;i>b;--i)
#define FOR1(i,a,b) for(int i=a;i<=b;++i)
#define INVFOR1(i, a, b) for(int i=a;i>=b;--i)
#define SZ(i) int(i.size())
#define eb emplace_back
#define ALL(i) i.begin(),i.end()
#define X first
#define Y second

int main() {
    int T;
    cin >> T;
    while(T--){
        vector<int> ap;
        int n, m;
        cin >> n >> m;
        int tmp;
        pii target;
        FOR(i, 0, n){    
            cin >> tmp;
            ap.eb(tmp);
            if(i==m){
                target.first=m;
                target.second = tmp;
            }
        }
        int index = 0;

        INVFOR(i, 9, target.second){
            
        }
    }




    return 0;
}