//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3139
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

int main() {

    string str;
    while(cin >> str){
        int head, end, prev, next;
        int a[100000];
        head = end = prev=next = 0;
        int sz = str.length();

        memset(a, -1, 100000*sizeof(int));
        
        FOR(i, 1, sz){
            if(str[i]=='['){
                a[i] = head;
                prev = i;
                //next = head;
                head = i;
            }else if(str[i]==']'){
                a[end] = i;
                prev = end;
                //next = i;
                end = i;
            }else{
                if(prev!=end){
                    a[i] = a[prev];
                    a[prev] = i;
                }else{ // a[prev] is end
                    a[prev] = i;
                    end = i;
                }
                prev = i;
            }
        }

        int idx = head;
        FOR(i, 0, sz){
            if(str[idx]!='['&&str[idx]!=']'){
                cout<<str[idx];
            }
            idx = a[idx];
        }
        cout<<endl;
    }



    return 0;
}