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