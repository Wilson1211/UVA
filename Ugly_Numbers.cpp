//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=72

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FOR(i,A,B) for(int i=A;i<B;++i)
#define FOR1(i,A,B) for(int i=A;i<=B;++i)
#define SZ(i) int(i.size())
#define eb emplace_back
#define pb pop_back
#define ALL(i) i.begin(),i.end()
#define X first
#define Y second


int main() {
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int arr[3]={2,3,5};
    set<ll> ss;
    pq.push(1);
    ll num, tmp;
    ll cnt = 0;
    while(1){
        num = pq.top();
        pq.pop();
        cnt++;
        if(cnt==1500){
            cout<<"ans: "<<num<<endl;
            break;           
        }
        FOR(j, 0, 3){
            tmp = num*arr[j];
            if(ss.find(tmp)==ss.end()){
                pq.push(tmp);
                ss.insert(tmp);
            }
        }
    }
}