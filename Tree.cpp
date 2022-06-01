//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=489
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

#define maxn 10001

int lleft[maxn], rright[maxn];
int node[maxn];

int str1_node[maxn];
int str2_node[maxn];
int str1_node_idx[maxn];
int str2_node_idx[maxn];
int cumulate[maxn];

int construct_tree(int l, int r, int cum){ // id is the root of str1[l~r] // return root
    if(l==r) {
        cumulate[str1_node[l]] = cum+str1_node[l];
        return str1_node[l];
    }
    int index = 0;
    int root;
    FOR1(i, l, r){
        if(index < str2_node_idx[str1_node[i]]){
            index = str2_node_idx[str1_node[i]];
            root = str1_node[i];
        }
    }
    // int index = str1_node_idx[id];
    // if(index != l) lleft[id] = str1_node[index-1];
    // if(index != r) {
    //     index = str2_node_idx[id];
    //     rright[id] = str2_node[index-1];
    // }

    //cumulate[lleft[id]] = cumulate[id]+id;
    //cumulate[rright[id]] = cumulate[id]+id;
    cumulate[root] = cum+root;
    index = str1_node_idx[root];
    int ll, rr;
    if(index != l){
        ll = construct_tree(l, index-1, cumulate[root]);
        lleft[root] = ll;
    }    
    if(index != r) {
        rr = construct_tree(index+1, r, cumulate[root]);
        rright[root] = rr;
    }
    return root;
}

int main() {

    string str1, str2;
    stringstream ss;
    
    bool flag = 1;
    while(flag){
        getline(cin, str1);
        if(str1=="") break;
        getline(cin, str2);
        int N=0;
        int num;
        ss.clear();
        ss << str2;
        while(ss >> str2_node[N]){
            N++;
        }
        ss.clear();
        ss << str1;
        FOR(i, 0, N){
            ss>> str1_node[i];
        }
// deal with str1_node_idx
// deal with str2_node_idx
        FOR(i, 0, N){
            int id = str1_node[i];
            str1_node_idx[id] = i;
            id = str2_node[i];
            str2_node_idx[id] = i;
        }

        memset(rright, 0, maxn*sizeof(int));
        memset(lleft, 0, maxn*sizeof(int));
        memset(cumulate, 0, maxn*sizeof(int));
        int root;
        root = construct_tree(0, N-1, 0);

        int min_node = 10001;
        int min_num = 10001;
        FOR(i, 0, N){
            int id = str1_node[i];
            if((lleft[id]|rright[id])==0){
                //cout<<"id: "<<id<<" cum:"<<cumulate[id]<<endl;
                if(min_num>cumulate[id]){
                    min_num = cumulate[id];
                    min_node = id;
                }else if(min_num==cumulate[id]){
                    if(min_node > id) min_node = id; 
                }
            }
        }
        cout<<min_node;
    }



    return 0;
}