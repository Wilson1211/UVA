//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1246
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

class node{
    public:
        void ins_par(int);
        void ins_chd(int);
        int par_sz();
        int chd_sz();

        vector<int> par;
        vector<int> chd;

    private:
};

void node::ins_par(int K){
    (this->par).eb(K);
}

void node::ins_chd(int K){
    (this->chd).eb(K);
}

int node::par_sz(){
    return (this->par).size();
}
int node::chd_sz(){
    return (this->chd).size();
}

int vt[101];

vector<int> ans;

void traverse(int K, node A[]){
    if(vt[K]==1) return;
    if(A[K].par_sz()==0) {
        vt[K] = 1;
        ans.eb(K);
        return;
    }
    FOR(i, 0, A[K].par_sz()){
        traverse((A[K].par)[i], A);
    }
    vt[K] = 1;
    ans.eb(K);
}

int main() {

    int n, m;
    while(cin>>n>>m){
        if(n ==0 && m == 0) break;
        memset(vt, 0, 101*sizeof(int));
        ans.clear();
        node A[101];
        int a, b;
        FOR(i, 0, m){
            cin >> a >> b;
            A[a].ins_chd(b);
            A[b].ins_par(a);
        }

        FOR1(i, 1, n){
            traverse(i, A);
        }
        FOR(i, 0, ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }



    return 0;
}