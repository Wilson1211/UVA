#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <algorithm>
using namespace std;

const int maxn = 144; // 144  
const int n_cut = 70; // 70
double price[maxn];

class Player {
    public:
        Player();
        char name[20];
        int rd[4];
        int dq; // with DQ, not qualified
        int amateur; // pro or amateur
        int first2rd;
        int rnd;
        int total;
};

Player::Player(){
    name[0] = '\0';
    for(int i=0;i<4;i++) rd[i] = 0;
    dq = 0;
    amateur = 0;
    first2rd = 0;
    rnd = -1;
    total = 0;
}

bool cmp1(const Player &a, const Player &b){ // true: a,b ; false: b,a



    if((a.dq)&&(b.dq)){
        if(a.rnd == b.rnd){
                return strcmp(b.name, a.name); 
            }else{
                return (b.rnd < a.rnd);
            }
    }else{
        if((a.dq) != (b.dq)){
            return (a.dq < b.dq);
        }else{ // both are qualified
            if(a.first2rd == b.first2rd){
                return strcmp(b.name, a.name); 
            }else{
                return (b.first2rd < a.first2rd);
            }
        }
    }
}

bool cmp2(const Player &a, const Player &b){
    if(a.total == b.total){
        return strcmp(b.name, a.name); 
    }else{
        return (a.total > b.total);
    }
}


int main(){

    int cases;
    cin >> cases;
    
    char s[40];
  
    Player player[maxn];


    while(cases--){
        int players_num;
        double purse; // total prizes
        //cin.getline(s,40); // empty line
        //cout<<"cases: "<<cases<<endl;

        // input prizes
        cin >> purse;
        //cout<<"purse: "<<purse<<endl;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore();
        for(int i=0;i<n_cut;i++) {
            cin.getline(s, 40);
            //cout << "price: " << s << endl;
            sscanf(s, "%lf", &price[i]);
        }
        //cin.getline(s, 40); // empty line

        // input players
        //cin.ignore();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(s, 40);
        int num_player;
        sscanf(s, "%d", &num_player);
        //cout<<"number of players: "<<num_player<<endl;
        for(int k=0;k<num_player;k++){
            //cin.ignore();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(s, 40);
            //cout <<"players: "<<s<<endl;
            strncpy(player[k].name, s, 20);
            if(strchr(player[k].name, '*')){
                player[k].amateur = 1;
            }
            
            //sscanf(s+20, "%d %d %d %d", rd[0], rd[1], rd[2], rd[3]);
            // 
            for(int j=0;j<4;j++){
                for(int i=0;i<3;i++){
                    if(!sscanf(s+20+j*3+i, "%d", &player[k].rd[j])) { // dq
                        player[k].dq = 1;
                        player[k].rnd = j-1;
                        break;
                    }
                }
                if(player[k].dq) break;
            }
            if(!player[k].dq){
                for(int i=0;i<2;i++){
                    player[k].first2rd += player[k].rd[i];
                }
                for(int i=2;i<4;i++){
                    player[k].total += player[k].rd[i];
                }
                player[k].total += player[k].first2rd;
                player[k].rnd = 3;
            }
        }

        //round 1, sort with 
        sort(player, player+num_player, cmp1);
        
        int i;
        for(i=0;i<num_player;i++){
            if(player[i].dq){
                break;
            }
        }
        if(i < num_player){
            num_player = i-1;
        }

        sort(player, player+num_player, cmp2);

    }

    return 0;
}