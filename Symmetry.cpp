//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4470

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

class cmp{
    bool operator ()(pii &a, pii &b){
        return a.first<b.first || (a.first==b.first)&&(a.second<b.second);
    }
};

int main(){


    int T;
    cin >>T;
    int n, m;
    while(T>0){
        cin >> n;
        int N = n;
        vector<pii> index;
        map<int, vector<int>> mmap; // y, vector x
        map<int, vector<int>>::iterator it;
        int x, y;
        while(n--){
            cin >> x >> y;
            index.eb(make_pair(x, y));
            if(mmap.find(y)==mmap.end()){
                mmap.insert(make_pair(y, vector<int>()));
            }
            mmap[y].eb(x);
        }

        for(it=mmap.begin();it!=mmap.end();it++){
            vector<int> *tmp;
            tmp = &(it->second);
            sort((*tmp).begin(), (*tmp).end());
        }
    
        double MID=0.1;
        int flag = 0;
        for(it=mmap.begin();it!=mmap.end();it++){
            vector<int> tmp;
            tmp = it->second;
            int sz = tmp.size();
            int middle = tmp[0]+tmp[sz-1];
            // cout<<"it: "<<it->first<<endl;
            // FOR(j, 0, sz){
            //     cout<<tmp[j]<<" ";
            // }
            if(MID!=0.1){
                if((int)MID != middle) {
                    cout<<"NO"<<endl;
                    // cout<<"MID: "<<MID<<" middle: "<<middle<<endl;
                    // cout<<"y: "<<it->first<<endl;
                    // FOR(j, 0, sz){
                    //     cout<<tmp[j]<<" ";
                    // }
                    flag = 1;
                    break;
                }
            }
            MID = middle;
            FOR(i, 1, sz/2){
                if(middle!=(tmp[i]+tmp[sz-1-i])){
                    cout<<"NO"<<endl;
                    // cout<<"middle: "<<MID<<endl;
                    // cout<<"i: "<<i<<" "<<tmp[i]<<" "<<tmp[sz-1-i]<<endl;
                    // cout<<"y: "<<it->first<<endl;
                    // FOR(j, 0, sz){
                    //     cout<<tmp[j]<<" ";
                    // }
                    // cout<<endl;
                    flag = 1;
                    break;
                } 
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    



        T--;
    }
}