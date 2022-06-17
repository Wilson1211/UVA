// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=640
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


vector<int> inp;
map<int, int> mm;

int indx;

bool readinput(){
    inp.clear();
    mm.clear();
   
    string str;
    stringstream ss;
    int num;
    indx = 0;
    getline(cin, str);
    ss.clear();
    ss << str;
    if(str=="-1") return 0;
    while(ss >> num){
        inp.eb(num);
    }
    return 1;
}

void solve(int idx){
    int a = inp[indx++];
    if(a==-1) return;
    if(mm.find(idx)!=mm.end()){
        mm[idx] += a;
    }else{
        mm.imp(idx, a);
    }

    solve(idx-1);
    solve(idx+1);
    return;
}
int main() {

    int z=1;
    while(readinput()){
        solve(0);
        map<int,int>::iterator it;
        cout<<"Case "<<z<<":\n";
        it = mm.begin();
        cout<<(*it).Y;
        it++;
        for(;it!=mm.end();it++){
            cout<<" "<<(*it).Y;
        }
        cout<<"\n"<<endl;
        z++;
    }


    return 0;
}



/*
void construct(vector<int> &inp){
    map<int, int> mm;
    int idx = 0;
    int flag = 0;// 0:left, 1:right
    mm.insert(make_pair(idx, inp[0]));
    
    FOR(i, 1, inp.size()){
        if(inp[i]==-1){
            flag = 1-flag;
            if(flag) idx+=2;
            else idx--;
        }else{
            idx--;
            if(mm.find(idx)!=mm.end()){
                mm[idx] += inp[i];
            }else{
                mm.imp(idx, inp[i]);
            }
        }
    }
    
    map<int, int>::iterator it;
    
    for(it=mm.begin();it!=mm.end();it++){
        cout<<(*it).X<<" "<<(*it).Y<<endl;
    }


}


int main() {

    string str;
    stringstream ss;
    while(getline(cin, str)&&str!="-1"){
        ss << str;
        vector<int> inp;
        int num;
        while(ss>>num) inp.eb(num);
        construct(inp);
    }


    return 0;
}
*/