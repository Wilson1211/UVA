//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=455
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

bool process(vector<int> &number, int &N){
    stack<int> que;
    int start = 1;
    FOR(i, 0, N){
        if(number[i]>start){
            FOR(j, start, number[i]){
                que.push(j);
            }
            start = number[i]+1;
        }else if(number[i]<start){
            int num = que.top();
            que.pop();
            if(num != number[i]){
                //cout<<"wrong1";
                return 0;
            }
        }else{
            start++;
        }
    }
    if(que.size()!=0) {
        while(que.size()){
            cout<<que.top()<<" ";
            que.pop();
        }
        return 0;
    }
    return 1;
}

int main() {
    int N;
    while(1){
        cin >> N;
        if(N==0) break;
        stringstream ss;
        string str;
        int num;
        cin.ignore();
        while(getline(cin, str)){
            if(str=="0"){
                break;
            }else{
                ss.clear();
                ss << str;
                vector<int> number;
                while(ss>>num){
                    number.eb(num);
                }
                bool flag;
                flag = process(number, N);
                if(flag) cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
        cout<<endl;
    }
    

}