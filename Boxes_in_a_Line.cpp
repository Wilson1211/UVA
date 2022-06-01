//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=602&page=show_problem&problem=4395
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

typedef struct box{
    int prev;
    int next;
}Box;


int main(){

    int N, c;
    int z = 1;
    while(scanf("%d%d", &N, &c)==2){
    //    cout<<N<<" "<<c<<endl;
        Box a[100002];
        int cmd, id1, id2;
        FOR1(i, 1, N){
            a[i].prev = i-1;
            a[i].next = i+1;
        }
        a[0].next = 1;
        a[N+1].prev = N;
        int direc = 0;// from left to right
        FOR(i, 0, c){
            scanf("%d", &cmd);
            if(cmd!=4){
                scanf("%d%d", &id1, &id2);
                //cout<<"cmd: "<<cmd<<" id1: "<<id1<<" id2: "<<id2<<endl;
            }
            if(cmd==1||cmd==2){
                if(direc==1) cmd = 3-cmd;
                a[a[id1].prev].next = a[id1].next;
                a[a[id1].next].prev = a[id1].prev;
                if(cmd==1){
                    a[id1].prev = a[id2].prev;
                    a[id1].next = id2;
                    a[a[id2].prev].next=id1;
                    a[id2].prev = id1;
                }else{
                    a[id1].prev = id2;
                    a[id1].next = a[id2].next;
                    a[a[id2].next].prev = id1;
                    a[id2].next = id1;
                }
            }else if(cmd==3){
                if(a[id1].next==id2){
                    a[a[id1].prev].next = id2;
                    a[a[id2].next].prev = id1;
                    a[id2].prev = a[id1].prev;
                    a[id1].prev = id2;
                    a[id1].next = a[id2].next;
                    a[id2].next = id1;
                }else if(a[id1].prev==id2){
                    a[a[id1].next].prev = id2;
                    a[a[id2].prev].next = id1;
                    a[id1].prev = a[id2].prev;
                    a[id2].next = a[id1].next;
                    a[id1].next = id2;
                    a[id2].prev = id1; 
                }else{
                    int tmp_next, tmp_prev;
                    tmp_next = a[id2].next;
                    tmp_prev = a[id2].prev;
                    a[a[id1].next].prev = id2;
                    a[a[id1].prev].next = id2;
                    a[id2].next = a[id1].next;
                    a[id2].prev = a[id1].prev;
                    
                    a[tmp_next].prev = id1;
                    a[tmp_prev].next = id1;
                    a[id1].next = tmp_next;
                    a[id1].prev = tmp_prev;
                }
            }else{
                direc = 1-direc;
            }
            // int idx;
            // idx = a[0].next;
            // FOR1(i, 1, N){
            //     cout<<idx;
            //     idx = a[idx].next;
            // }
            // cout<<endl;
        }
        ll sum=0;
        int idx;
        // idx = a[0].next;
        // FOR1(i, 1, N){
        //    cout<<a[idx].id;
        //    idx = a[idx].next;
        // }
        // cout<<endl;
        if(direc==0||N%2==1){
            idx = a[0].next;
        }else{
            idx = a[0].next;
            idx = a[idx].next;
        }
        for(int i=1;i<=N;i+=2){
            sum += idx;
            idx = a[idx].next;
            idx = a[idx].next;
        }
        // }else{
            
        //     idx = a[N+1].prev;
        //     cout<<"idx: "<<idx<<endl;
        //     for(int i=N;i>=1;i-=2){
        //         cout<<"idx: "<<idx<<" id: "<<a[idx].id<<endl;
        //         sum += a[idx].id;
        //         idx = a[idx].prev;
        //         idx = a[idx].prev;
        //     }
        // }
        cout<<"Case "<<z++<<": "<<sum<<endl;
    }

    return 0;
}