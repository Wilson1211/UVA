//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4467
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

#define maxr 10000+5
#define maxc 10+5

map<string, int> mmap;
vector<string> ID;

void setID(string s){
    if(mmap.find(s)==mmap.end()){
        ID.eb(s);
        mmap.insert(make_pair(s, ID.size()-1));
    }
}

int getID(string s){
    if(mmap.find(s)==mmap.end()){
        setID(s);
    }
    return mmap[s];
}

int main() {

    int n, m;
    string s, s2;
    while(getline(cin, s)){
        stringstream stss(s);
        ID.clear();
        mmap.clear();
        stss >> n >> m;
        int d[maxr][maxc];
        
        FOR(i, 0, n){
            getline(cin, s);
            int lastpos = -1;
            FOR(j, 0, m){
                int p = s.find(',', lastpos+1);
                if(p==string::npos) p = s.length();
                s2 = s.substr(lastpos+1,p-1-lastpos);
                d[i][j] = getID(s2);
                lastpos = p;
            }
        }

        int flag = 0;
        int idx1, idx2;
        FOR(i, 0, m){
            FOR(j, i+1, m){
                map<pii, int> mm;
                FOR(k, 0, n){
                    idx1 = d[k][i];
                    idx2 = d[k][j];
                    pii p = make_pair(idx1, idx2);
                    //cout<<"idx1: "<<idx1<<" idx2: "<<idx2<<endl;
                    if(!mm.count(p)){
                        mm.insert(make_pair(p, k));
                    }else{
                        cout<<"NO"<<endl;
                        cout<<mm[p]+1<<" "<<k+1<<endl;
                        //cout<<"p: "<<p.first<<" "<<p.second<<endl;
                        cout<<i+1<<" "<<j+1<<endl;
                        flag = 1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            if(flag == 1) break;
        }
        if(flag ==0){ cout<<"YES\n";}
    }

    // map<string, int>::iterator it;
    // for(it = mmap.begin();it!=mmap.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }

    return 0;
}


/*
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <stringstream>

using namespace std;

typedef pair<string, int> Pair;
typedef pair<int, int> Pair_int;


map<string, int> mmap;
map<Pair_int, Pair_int> database;

map<string, int>::iterator it;
map<Pair_int, Pair_int>::iterator it_d;

int main(){


    string ss;
    int **a;
    int n, m;

    a = (int **)malloc(n*sizeof(int*));
    a[0] = (int*)malloc(n*m*sizeof(int));


    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ss;
            it = mmap.find(ss);
            if(it == mmap.end()){
                mmap.insert(Pair(ss, mmap.size()) );
                a[i][j] = mmap.size();
            }else{
                a[i][j] = it->second;
            }
        }
    }

    Pair_int column;
    Pair_int row;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            column = make_pair(i,j);
            for(int k=0;k<n;k++){
                row = make_pair(a[k][i], a[k][j]);
                it_d = database.find(row);
                if(it_d != database.end()){
                    cout<<"row ( "<< (it_d->first).first << ", "<< k << " )" << " column ( " << i << ", " << j << " )" << endl;
                }else{
                    database.insert({ row, column});
                }
            }
        }
    }


    free(a[0]);
    free(a);

    return 0;
}
*/

/*
while(getline(cin, s)) {
    stringstream ss(s);
    if(!(ss >> n >> m)) break;
    cnt = 0;
    id.clear();
    for(int i = 0; i < n; i++) {
      getline(cin, s);
      int lastpos = -1;
      for(int j = 0; j < m; j++) {
        int p = s.find(',', lastpos+1);
        if(p == string::npos) p = s.length();
        db[i][j] = ID(s.substr(lastpos+1, p - lastpos - 1));
        lastpos = p;
      }
    }
    find();
  }
  */