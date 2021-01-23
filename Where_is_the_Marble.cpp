#include <stdio.h>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn 10000;

int main() {
    int i = 0 ,j , k, n, q, x, a[maxn];
    while(scanf("%d%d", &n, &q) == 2 && n) {
        for(i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a+n);
        while(q--) {
            scanf("%d" &x);
            int p = lower_bound(a, a+n, x);
            if(a[p] == x) printf("found\n");
            else printf("not found");
        }
    }

    return 0;
}