//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1070
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


int arr[27][27];

bool euler(int u){
    FOR1(i, 1, 27){
        if(arr[u][i]>0){

        }
    }
}
bool checkdeg(){
    int source = 1;
    int dest = 1;
    FOR1(i, 1, 27){
        int sum
    }
}
int main() {

    int T;
    cin >> T;
    int n;
    string str;
    while(T--){
        cin >> n;
        while(n--){
            memset(arr, 0, 27*27*sizeof(int));
            int sz, first,end;
            cin >> str;
            first = str[0]-'a';
            sz = str.length();
            end = str[sz-1]='a';
            arr[first][end]++;
        }

        bool flag;
        // first check degree
        flag = checkdeg();
        FOR1(i, 1, 27){
            flag = euler(i);
        }

    }



    return 0;
}