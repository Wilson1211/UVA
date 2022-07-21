//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4474
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


const int maxn = 100000 + 5;
const int INF = 1000000000; // maximal color

class Edge {
public:
	int u, v, c;
	//Edge () {}
	Edge(int u=0, int v=0, int c=0):u(u),v(v),c(c) {}
	Edge operator = (Edge node){
		Edge tmp;
		tmp.u = node.u; tmp.v = node.v; tmp.c = node.c;
		return tmp;
	}
private:
};

vector<Edge> edges;
vector<int> G[maxn];

vector<int> ans;

void AddEdge(int u, int v, int c) {
	edges.push_back(Edge(u, v, c));
	int idx = edges.size() - 1;
	G[u].eb(idx);
}

int n, vis[maxn];
int d[maxn];
// forward bfs to construct the path
void bfs() {
	queue<int> bfs_q; 
	vector<int> tmp_bfs_q;
	int node, layer_cnt = 1, tmp_layer_cnt=0;
	int mincolor = maxn;
	memset(vis, 0, maxn*sizeof(int));

	bfs_q.push(1);
	while(bfs_q.size()>0){
		node = bfs_q.front();
		bfs_q.pop();

		vis[node] = 1;
		int sz = G[node].size();
		int v,c = maxn;
		FOR(i, 0, sz){
			
			v = edges[G[node][i]].v; c = edges[G[node][i]].c;
			if((vis[v]==0)&&(d[v]==d[node]-1)){
				
				if((c<mincolor)){
					tmp_bfs_q.clear();
					tmp_layer_cnt = 0;

					tmp_bfs_q.eb(v);
					mincolor = c;
					tmp_layer_cnt++;
				}else if(c==mincolor){
					tmp_bfs_q.eb(v);
					tmp_layer_cnt++;
				}
			}
		}

		layer_cnt--;
		if(layer_cnt==0 && maxn>mincolor){
			ans.eb(mincolor);

			layer_cnt = tmp_layer_cnt;
			tmp_layer_cnt = 0;
			mincolor = maxn;
			sz = tmp_bfs_q.size();
			FOR(i, 0, sz){
				bfs_q.push(tmp_bfs_q[i]);
			}
			tmp_bfs_q.clear();
		}
		
	}
}


  // reverse bfs to find out the distance from each node to n-1
void rev_bfs() {

	memset(d, n, maxn*sizeof(int));
    queue<int> bfs_que;
    int node;
    bfs_que.push(n);
	d[n] = 0;
    while(bfs_que.size()>0){
		node = bfs_que.front(); bfs_que.pop();
		vis[node] = 1;
		int sz = G[node].size();
		int v;
		FOR(i, 0, sz){
			v = edges[G[node][i]].v;
			if(vis[v]==0){
				bfs_que.push(v);
				d[v] = (d[v]<=d[node]+1)?d[v]:(d[node]+1);
			}
		}
    }
}

int main() {
    int u, v , c, m;
    while(scanf("%d%d", &n, &m)==2){
		FOR(i, 0, m){
			cin >> u >> v >> c;
			AddEdge(u,v,c);
			AddEdge(v,u,c);
		}

		rev_bfs();
		bfs();

		cout<<"dist: "<<d[1]<<endl;
		FOR(i, 0, ans.size()){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
    }
    
}