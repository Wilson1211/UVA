#include <bits/stdc++.h>
//
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

#define maxn 100001
#define maxm 200001

int edge[100001][100001];
int count[100001][100001];

void dfs(int column, int step, int total_row){
  FOR1(i, 1, total_row){
    if(edge[i][column]!=0){
      count[i][]
    }
  }
}

int main() {

  int n, m;
  string str;
  while(getline(cin, str) && str != ""){
    //init
    memset(edge, 0, sizeof(int)*maxn*maxn)
    memset(count, maxn, sizeof(int)*maxn*maxn)
    stringstream ss;
    ss >> n;
    ss >> m;
    FOR(i, 0, m){
      cin >> l >> r >> c;
      edge[l][r] = c;
    }
    dfs(n, 0, n);
    
  }


  return 0;
}