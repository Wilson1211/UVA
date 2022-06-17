//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=243&page=show_problem&problem=3252
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

int main() {

    int T;
    cin >> T;
    while(T--){
        int a[100][2];
        int n, m;
        int maxnum = 0;
        cin >> n >> m;

        FOR(i, 0, n){
            cin >> a[i][0];
            maxnum = max(maxnum, a[i][0]);
        }
        int k = a[m][0];// k represents the priority

        int minutes = 0;
        int flg=0;
        int start = 0;
        INVFOR1(j, maxnum, k){
            int ind = start;
            FOR(i, 0, n){
                if(a[ind][0]==j){
                    if(ind==m){
                        cout<<++minutes<<endl;
                        flg=1;
                        break;
                    }else{
                        a[ind][1] = ++minutes;
                    }
                    start = ind;
                }
                ind++;
                ind %= n;
            }
            if(flg==1) break;
        }

    }


    return 0;
}