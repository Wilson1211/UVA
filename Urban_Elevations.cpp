#include <iostream>
#include <string>
#include <set>

int n;
#define maxn 100 + 5

class Building {
    Building(); // constructor
    int index;
    int x, y, w, d, h;
    bool operator < (Building &rhs) const { // const means this function can't alter input value
        return (x < rhs.x) || (x == rhs.x && y < rhs.y);
    }
}b[maxn];

double x[maxn*2]; // store the x coordinate


Building::Building(){
    x = 0;
    y = 0;
    w = 0;
    d = 0;
    h = 0;
}

bool cover(int i, int mx){
    if(b[i].x < mx && b[i].x+b[i].w > mx) return true;
    return false;
}

bool vis(int i, int mx){
    if(!cover(i, mx)) return false;
    for(int j=0;j<n;j++){
        if(j == i || !cover(j, mx)) continue;
        if(b[j].y < b[i].y && b[j].h >= b[i].h) return false;
    }
    return true;
}

int main() {
    cin >> n;
    int i=0;

    while(cin >> n && n != 0){
        for(int i=0;i<n;i++){
            cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
            b[i].index = i+1;
            x[2*i] = b[i].x; m[2*i+1] = b[i].x+b[i].w;
        }
        sort(b, b+n);
        sort(x, x+2*n);

        int m = unique(x, x+2*n) - x;  // coordinate x without duplicate

        for(int i=0;i<m-1;i++){
            for(j=0;j<n;j++){
                if(!cover(j, (x[i]+x[i+1])/2)) continue;
                if(vis(j, (x[i]+x[i+1])/2)){
                    printf(" %d", b[i].id);
                    break;
                }
            }
        }
        printf("\n");

    }

}