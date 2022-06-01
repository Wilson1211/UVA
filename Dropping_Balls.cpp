//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=620
#include <bits/stdc++.h>
// use array to represent the tree
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
    int N;
    cin >> N;
    while(N--){
        int D, I;
        cin >> D >> I;
        ll index = 1;
        FOR(i, 0, D-1){
            index<<=1;
            if(I%2==0){
                index++;
            }
            I = (I+1)/2;
        }
        cout<<index<<endl;
    }
    cin >> N;

    return 0;
}

/*
void print_ceil(int a[], ll &ceil){
    cout<<"ceil: "<<ceil<<endl;
    FOR1(i, 1, ceil){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int N;
    cin >> N;
    while(N--){
        int D, I;
        cin >> D >> I; // atmost 2^D-1
        int a[1050000]={};

        ll ceil;
        ceil = (1<<D)-1;
        int count = 1;
        while(count<=I){
            ll index = 1;
            while(index<=ceil){
                if(a[index]==1) {
                    a[index] = 0;
                    index <<= 1;
                    index++;
                }else{
                    a[index] = 1;
                    index <<= 1;
                }
            }
            //print_ceil(a, ceil);
            index >>= 1;
            if(count == I) cout<<index<<endl;
            count++;
        }
    }

    cin >> N;

    return 0;
}
*/