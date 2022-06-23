//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1070
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


int arr[27][27];

void traverse(int begin, int &count){
    FOR1(i, 1, 26){
        if((begin != i)&&(arr[begin][i]>0)){
            arr[begin][i]--;
            count++;
            traverse(i, count);
        }
    }
}


int main() {

    int T;
    cin >> T;
    int n;
    while(T--){
        int count = 0;
        cin >> n;
        memset(arr, 0, 27*27*sizeof(int));

        string str;
        FOR(i, 0, n){   
            cin >> str;
            int a, b, sz;
            a = str[0];
            sz = str.length();
            b = str[sz-1];
            arr[a-'a'+1][b-'a'+1]++;
        }

        bool flag=0;
        int begin=0, end=0;
        int inp, outp;
        FOR1(i, 1, 26){
            inp = 0;outp=0;
            FOR1(j, 1, 26){
                if(i!=j) {
                    outp += arr[i][j];
                    inp += arr[j][i];
                }
            }

            if((outp-inp)==1){
                if(begin==0) begin = i;
                else flag=1;
            }else if((inp-outp)==1){
                if(end==0) end = i;
                else flag=1;
            }else if((outp-inp)>1 || (inp-outp)>1) {
                flag= 1;
            }
            
            if(flag==1) {
                cout<<"NOT possible\n";
                cout<<begin<<" 1 "<<end<<endl;
                break;
            }
        } 

        if(flag==1) continue;

 

        flag = 0;
        if(begin==end){
            FOR1(i, 1, 26){
                FOR1(j, i+1, 26){
                    if(arr[i][j]!=0){
                        traverse(i, count);
                        flag = 1;
                        break;
                    }
                }
                if(flag==1) break;
            }
        }else if(begin==0||end==0){
            cout<<"NOT possible\n";
            cout<<begin<<" 2 "<<end<<endl;
            flag = 1;
        }else{
            traverse(begin, count);
        }

        if(!flag) cout<<"YES\n";

    }



    return 0;
}