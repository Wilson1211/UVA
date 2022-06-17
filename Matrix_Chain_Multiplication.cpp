//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=6&page=show_problem&problem=383
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

int main(){

    int i, j, k;
    int N;
    cin >> N;
    vector<pii> mat;
    FOR(i, 0, N){
        int z, x;
        char cc;
        //cin >> cc >> z >> x;
        scanf("%s%d%d", &cc, &z, &x);
        mat.eb(make_pair(z, x));
//        cout<<cc<<" "<<z<<" "<<x<<endl;
    }
    string str;
    while(cin >> str){
        int ans = 0;
        int n = str.length();
        stack<pii> st;
        //cout<<"str: "<<str<<" n: "<<n<<endl;
        FOR(i, 0, n){
            if(str[i]==')'){
                int n1, m1, n2, m2;
                n2 = (st.top()).first;
                m2 = (st.top()).second;
                st.pop();
                n1 = (st.top()).first;
                m1 = (st.top()).second;
                st.pop();
                if(m1!=n2) {
       //             cout<<n1<<" "<<m1<<" "<<n2<<" "<<m2<<endl;
                    cout<<"error\n"; 
                    ans = -1;
                    break;
                }

                ans += n1*m1*m2;
                st.push(make_pair(n1, m2));
            }else if(isalpha(str[i])){
                st.push(mat[str[i]-'A']);
            }
        }
        if(ans>=0){
            cout<<ans<<endl;
        }
    }


    return 0;
}