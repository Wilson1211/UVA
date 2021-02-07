#include <iostream>
#include <stdio.h>
#include <fstream>


using namespace std;

bool check(int *b, const int &n){
    for(int i=0;i<n;i++){
        if(b[i] != 0) return 0;
    }
    return 1;
}

void print_Array(int *a, const int &n) {
    for(int i=0;i<n;i++) cout<< a[i] << " ";
    cout<<endl;
}

int main() {
    
    //ofstream  file;
    //file.open("output.txt");
    int loop = 1000;

    int cases, num;
    bool flag = 0;
    int *a, *b, *tmp;
    cin >> cases;
    while(cases--){

        cin >> num;
        a = (int*)malloc(num*sizeof(int));
        b = (int*)malloc(num*sizeof(int));
        for(int i=0;i<num;i++){
            cin >> a[i];
        }

        loop = 999;flag = 0;
        for(int i=0;i<num-1;i++){
            b[i] = abs(a[i]-a[i+1]);
        }
        b[num-1] = abs(a[num-1]-a[0]);
        flag = check(b, num);

        swap(a,b);
        
        while(loop-- && (1-flag)){
            for(int i=0;i<num-1;i++){
                b[i] = abs(a[i]-a[i+1]);
            }
            b[num-1] = abs(a[num-1]-a[0]);
            //print_Array(b, num);
            flag = check(b, num);
            swap(a, b);
        }

        if(flag){
            cout<<"ZERO\n";
            //file <<"ZERO\n";
        }else{
            cout<<"LOOP\n";
            //file<<"LOOP\n";
        }

        
        free(b);
        free(a);
    }

    //file.close();



    return 0;
}