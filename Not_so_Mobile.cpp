//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=780
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
class node{
public:
    node():weight(0), edge(0){}
    int lleft;
    int rright;
    int weight;
    int edge;
};

node Node[maxn];
vector<string>input;

int idx; // index: in input vector
int cnt;
int construct_tree(int edge){ 
    node A = Node[cnt++];
    A.edge = edge;
    stringstream ss;
    ss.clear();
    ss<<input[idx];
    int left_weight, right_weight;
    int w1,d1,w2,d2;
    ss>>w1;ss>>d1;ss>>w2;ss>>d2;
    if(w1==0){
        idx++;
        left_weight = construct_tree(d1);
        if(left_weight==-1) return -1;
    }else{
        left_weight = w1;
    }

    if(w2==0){
        idx++;
        right_weight = construct_tree(d2);
        if(right_weight==-1) return -1;
    }else{
        right_weight = w2;
    }

    if(left_weight*d1!=right_weight*d2) return -1;
    A.weight = left_weight+right_weight;
    return A.weight;
}


int main() {

    string str;
    int N;
    cin >> N;
    cin.ignore();
    while(N--){
        input.clear();
        while(getline(cin, str)){
            input.eb(str);
        }
        idx = 0;
        cnt=0;
        int flag;
        //cout<<"input size: "<<input.size()<<endl;
        //FOR(i, 0, input.size()) cout<<input[i]<<endl;
        flag = construct_tree(0);
        if(flag==-1) cout<<"NO\n";
        else cout<<"YES\n";
    }


    return 0;
}