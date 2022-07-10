//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=17&page=show_problem&problem=1503
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

#define maxn 210

char buf[maxn][maxn];

void dfs(int layer, int pos){
    cout<<buf[layer][pos];
    cout<<"(";
    if(buf[layer+1][pos]=='|'){
        int left,right;
        int position = pos;
        while(buf[layer+2][position]=='-') position--;
        left = ++position;
        position = pos;
        while(buf[layer+2][position]=='-') position++;
        right = --position;
        //cout<<"left: "<<left<<" pos: "<<pos<<" right: "<<right<<endl;
        FOR1(i, left, right){
            //cout<<buf[layer+3][i]<<" "<<isalpha(buf[layer+3][i])<<endl;
            if(isalpha(buf[layer+3][i])){
                dfs(layer+3, i);
            }
        }
    }
    cout<<")";
}

void solve(){

    memset(buf, 0, maxn*maxn*sizeof(char));
    int n=0;
    for(;;){
        cin.getline(buf[n], maxn);
        if(buf[n][0]=='#') break;
        else n++;
    }

    cout<<"(";
    FOR(i, 0, maxn){
        if(buf[0][i]!=' '){
            dfs(0, i);
            break;
        }
    }
    cout<<endl;
}

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while(T--) solve();

    return 0;
}


/*

    A
    |
--------
B  C   D
   |   |
 ----- -
 E   F G
#
e
|
----
f g
#
*/