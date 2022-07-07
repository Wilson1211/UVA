// UVa12171 Sculpture
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;
const int maxc = 1000 + 1;

// original data
int n, x0[maxn], y0[maxn], z0[maxn], x1[maxn], y1[maxn], z1[maxn];

// discretization related
int nx, ny, nz;
int xs[maxn*2], ys[maxn*2], zs[maxn*2];

// floodfill related
const int dx[] = {1,-1,0,0,0,0};
const int dy[] = {0,0,1,-1,0,0};
const int dz[] = {0,0,0,0,1,-1};
int color[maxn*2][maxn*2][maxn*2];

struct Cell {
  int x, y, z;
  Cell(int x=0, int y=0, int z=0):x(x),y(y),z(z){}
  bool valid() const {
    return x >= 0 && x < nx-1 && y >= 0 && y < ny-1 && z >= 0 && z < nz-1;
  }
  bool solid() const {
    return color[x][y][z] == 1; // solid
  }
  bool getVis() const {
    return color[x][y][z] == 2; // visited
  }
  void setVis() const {
    color[x][y][z] = 2;
  }
  Cell neighbor(int dir) const {
    return Cell(x+dx[dir], y+dy[dir], z+dz[dir]);
  }
  int volume() const {
    return (xs[x+1]-xs[x])*(ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
  }
  int area(int dir) const {
    if(dx[dir] != 0) return (ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
    else if(dy[dir] != 0) return (xs[x+1]-xs[x])*(zs[z+1]-zs[z]);
    return (xs[x+1]-xs[x])*(ys[y+1]-ys[y]);
  }
};

void discretize(int* x, int& n) {
  sort(x, x+n);
  n = unique(x, x+n) - x;
}

int ID(int* x, int n, int x0) {
  return lower_bound(x, x + n, x0) - x;
}

void floodfill(int& v, int& s) {
  v = 0;
  s = 0;
  Cell c;
  c.setVis();
  queue<Cell> q;
  q.push(c);
  while(!q.empty()) {
    Cell c = q.front(); q.pop();
    v += c.volume();
    // 因為在queue裡面的都是color!=1 的，也就是不solid的，
    //因此計算體積就是c.vloume就是在color上X,Y,Z，也就是在xs[X] ys[Y] zs[Z]上的座標到下個xs[X+1],ys[Y+1],zs[Z+1]中間都不會有實體的東西
    //因為若有實體的東西，那麼X,Y,Z到下個X+1,Y+1,Z+1中間就起碼有一項會被中間實體的東西取代
    //並且一定會從實體的0,0,0開始，並以此為圓心開始慢慢向周圍擴散
    for(int i = 0; i < 6; i++) {
      Cell c2 = c.neighbor(i); // 此為在 color 上做
      if(!c2.valid()) continue;
      if(c2.solid()) s += c.area(i);
      //因為c是某個在color 上的座標，並且計算area的時候都是計算到下個有效位置的座標，因此不會出現重複計算area的情況
      else if(!c2.getVis()){
        c2.setVis();
        q.push(c2);
      }
    }
  }
  v = maxc*maxc*maxc - v;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    nx = ny = nz = 2;
    xs[0] = ys[0] = zs[0] = 0;
    xs[1] = ys[1] = zs[1] = maxc;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {  // n atmost 50
      scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
      x1[i] += x0[i]; y1[i] += y0[i]; z1[i] += z0[i];
      xs[nx++] = x0[i]; xs[nx++] = x1[i];
      ys[ny++] = y0[i]; ys[ny++] = y1[i];
      zs[nz++] = z0[i]; zs[nz++] = z1[i];
    }
    discretize(xs, nx);
    discretize(ys, ny);
    discretize(zs, nz);

    // paint
    memset(color, 0, sizeof(color));
    for(int i = 0; i < n; i++) {
      int X1 = ID(xs, nx, x0[i]), X2 = ID(xs, nx, x1[i]);
      int Y1 = ID(ys, ny, y0[i]), Y2 = ID(ys, ny, y1[i]);
      int Z1 = ID(zs, nz, z0[i]), Z2 = ID(zs, nz, z1[i]);
      for(int X = X1; X < X2; X++)
        for(int Y = Y1; Y < Y2; Y++)
          for(int Z = Z1; Z < Z2; Z++)
            color[X][Y][Z] = 1; // 在 xs,ys,zs 上的第X,Y,Z的位置上
    }

    int v, s;
    floodfill(v, s);
    printf("%d %d\n", s, v);
  }

  return 0;
}
