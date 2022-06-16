//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=513

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

int cnt;
int x, y;

void traverse(int (*arr)[101], int a, int b){
    arr[a][b] = cnt;
    for(int i=a-1;i<=a+1;i++){
        for(int j=b-1;j<=b+1;j++){
            if(i==a&&j==b) continue;
            if((i>=0)&&(i<x)&&(j>=0)&&(j<y)){
                if(arr[i][j]==-2){
                    traverse(arr, i, j);
                }
            }
        }
    }
    return;
}

void find(int (*arr)[101]){
    FOR(i, 0, x){
        FOR(j, 0, y){
            if(arr[i][j]==-2){
                traverse(arr, i, j);
                cnt++;
            }
        }
    }
}

int main() {

    char c;
    while((cin>>x>>y) &&(x+y!=0) ){
        int arr[101][101];
        FOR(i, 0, x){
            FOR(j,0,y){
                cin >> c;
                arr[i][j]=(c=='*')?-1:-2;
            }
        }
        cnt = 0;
        find(arr);
        cout<<cnt<<endl;
    }

    return 0;
}