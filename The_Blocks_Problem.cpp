#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn 30;
int n;
vector<int> pile[maxn];

void find_pile(int a, int& p, int& h){
    for(p = 0; p < n; p++) {
        for(h = 0; h < pile[p].size(); h++) if(pile[p][h] == a) return;
    }
}
void clear_above(int a, int p, int h){
    for(int i = h + 1; i < pile[p].size; i++) {
        int b = pile[p][i];
        pile[b].push_back(b);
        //pile[p].pop();
    }
    pile[p].resize(h + 1);
}
void pile_over(int a, int p1, int h, int p2){
    for(int i = h; i < pile[p1].size(); i++)
        pile[p2].push_back(pile[p1][i]);
    pile[p1].resize(h);
}

int main () {
    int i, j, k;
    int a, b;
    string sa, sb;
    cin >> n;
    for(i = 0; i < n; i++) pile[i].push_back(i);
    while(cin >> sa >> a >> sb >> b) {
        int pa, pb, ha, hb;
        find_pile(a, pa, ha);
        
    }
    
    


    return 0;
}