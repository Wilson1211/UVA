
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

#define maxn 101

int edge[101][101]; // color
int ccount[101][101]; // distance from n
int mincount[101];
int existed[101];

int N, M;
int ddist;
vector<int> ans;
void p_ans(){
    FOR(i, 0, ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

queue<int> bfs_que;
void dfs(int, int);
void bfs(int node, int cnt){ // cnt belongs to the layer of node's neighbor

    //existed[node] = 1;
    FOR(i, 1, N){ // no need to test n
        if((i!=node)&&(edge[i][node]!=0) && (mincount[i]>=cnt)){ //
            if(mincount[i]>cnt) mincount[i] = cnt; 
            //if(ccount[i][node] > cnt) ccount[i][node] = cnt;
            ccount[i][node] = cnt;
            if(i!=1) bfs_que.push(i);
            else{ // i==1
                if(ddist > cnt) ddist = cnt;
            }
        }
    }
    if(bfs_que.size()>0){
        int nn = bfs_que.front();
        bfs_que.pop();
        bfs(nn, ccount[nn][node]+1);
    }
}
    

int main() {
    string intp;
    stringstream ss;
    while(getline(cin, intp)&&(intp!="")){
        ss << intp;
        ss >> N; ss >> M;

        memset(edge, 0, sizeof(int)*maxn*maxn);
        memset(existed, 0, sizeof(int)*maxn);
        memset(mincount, maxn, sizeof(int)*maxn);
        memset(ccount, maxn, sizeof(int)*maxn*maxn);
        ddist = maxn;
        int a,b,c;
        FOR(i, 0, M){
            cin >> a >> b >> c;

            edge[a][b] = c;
            edge[b][a] = c;
        }


        bfs(N,1);

        dfs(1, ddist);


        // existed[n] = 1;
        // FOR(i, 1, n){ // no need to check n
        //     if(edge[i][n]!=0) {
        //         bfs_que.push(i);
        //     }
        // }
    }
}

void dfs(int node, int dist){
    if(node == N){
        p_ans();
    }
    else{
        int mincol = maxn;
        FOR1(i, 2, N){
            if(ccount[node][i]==dist){
                if(mincol > edge[node][i]) mincol = edge[node][i];
            }
        }
        FOR1(i, 2, N){
            if(ccount[node][i]==dist && (edge[node][i]==mincol)){
                ans.eb(i);
                dfs(i, dist-1);
                ans.pop_back();
            }
        }
    }
}

/*
void dfs_process(int column, int cnt, int prev){
    if(column == 1){
        if(min_edge_cnt < cnt+1) return;
        if(min_edge_cnt > cnt+1){
            min_edge_cnt = cnt+1;
        }
    }
    if(ccount[column][prev]> cnt){
        ccount[column][prev] = cnt;
        FOR(i, 1, n){
            if(i!=column){
                if(edge[i][column]!=0){
                    dfs_process(i, cnt+1, column);
                }
            }
        }
    } 
}
*/