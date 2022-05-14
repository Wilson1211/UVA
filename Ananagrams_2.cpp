// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=92

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

bool myfunc(string &a, string &b){
    int sz_a = a.length();
    int sz_b = b.length();
    int sz = min(sz_a, sz_b);
    FOR(i, 0, sz){
        if(a[i]!=b[i]){
            return a[i]<b[i];
        }
    }
    return sz_a<=sz_b;
}

void preprocess(string &tmp_str){
    FOR(i, 0, tmp_str.length()){
        tmp_str[i] = tolower(tmp_str[i]);
    }
    sort(tmp_str.begin(), tmp_str.end(), less<char>());
}

int main(){

    string str, tmp_str;
    map<string, int> mm;
    vector<string> ans;
    while(getline(cin, str)&&(str!="#")){
        tmp_str = str;
        preprocess(tmp_str);
        //sort(tmp_str.begin(), tmp_str.end(), less<char>());
        if(mm.find(tmp_str)==mm.end()){
            mm[tmp_str] = 1;
        }else{
            mm[tmp_str]++;
        }
    }

    sort(ans.begin(), ans.end(), myfunc);
    FOR(i, 0, ans.size()){
        
        cout<<ans[i]<<endl;
    }
    return 0;
}