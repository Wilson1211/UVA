#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

    //queue<int> Que, Que_b;
    vector<int> Que, Que_b;

    char ss[20];
    int k, input;

    // input

    while(cin >> input && input != 0){

        Que.clear();
        for(int i=1;i<=input;i++) Que.push_back(i);
    

        cout<<"Discarded cards:";
        while(Que.size()>3){
            //while(!Que_b.empty()) Que_b.pop();
            Que_b.clear();
            for(int i=1;i<=Que.size();i+=2) {
                cout<<" "<<Que[i-1];
                if(i != Que.size()) Que_b.push_back(Que[i]);
            }
            if((Que.size()%2==1)){
                    k = Que_b.front();
                    Que_b.erase(Que_b.begin());
                    Que_b.push_back(k);
            }
                
            
            //cout<<endl;
            swap(Que, Que_b);
        }
        if(Que.size() == 1) {
            cout<<"Remaining card: ";
            cout<<Que[0];
        }else { // 2 or 3
            
            cout<<" "<<Que[0];
            if(Que.size() == 3) cout<<" "<<Que[2];
            cout<<endl;
            cout<<"Remaining card: "<<Que[1];
        }
        cout<<endl;
    }

    return 0;
}