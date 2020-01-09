#include <stdio.h>

#define maxn 21
int arr[maxn] = {};

int go(int* arr, int p1, int d) {

    int ptr = p1;
    while(!ptr) ptr = arr[(p1+d+n-1)%n+1];
    printf("%d", ptr);
    return ptr;
}


int main() {
    int n, k, m;
    int left, pk, pm;
    scanf("%d%d%d", &n, &k, &m);
    left = n;
    pk = 1;
    pm = n;
    for(int i = 1; i <= n; i++) arr[i] = i;
    while(left) {
        p1 = go(arr, p1, k);
        p2 = go(arr, p2, m);
    }
    left--;
    if(p1 == p2) left--;

    return 0;
}