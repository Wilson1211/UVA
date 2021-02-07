#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){


    int i, j, k;
    int num;
    //int *a, *b;
    vector<int> a, b;

    while(cin >> num && num != 0){
        a.clear();
        b.clear();

        for(int i=0;i<num;i++){
            cin >> j >> k;
            a.push_back(j);
            b.push_back(k);
        }

        sort(a.begin(), a.begin()+num);
        sort(b.begin(), b.begin()+num);

        if(a == b) cout<<"YES\n";
        else cout<<"NO\n";


    }






    return 0;
}