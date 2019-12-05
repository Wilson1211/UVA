//#define LOCAL
#include <stdio.h>
#include <string.h>
#define str_len 85

int check_period_str(char *a, int len) {

    int j, n, ret;
    char ft[str_len], st[str_len];

    strncpy(ft, a, len);
    printf("ft = %s\n", ft);
    n = strlen(a);
    j = n / len;
    while(--j) {
        a += len;
        strncpy(st, a, len);
        printf("st = %s\n", st);
        ret = strcmp(st, ft);
        
        if(ret != 0) return 0;
    }
    return len;
}



int main() {

#ifdef LOCAL
    FILE *fin, *fout;
    fin = fopen("Periodic_Strings_input.txt", "r");
    fout = fopen("output.txt", "w");
#endif
    char a[str_len];
    int i, r, n, k;
    scanf("%d", &k);
    while(k--) {
        scanf("%s", a);
        //n = (strlen(a) + 1) / 2;
        n = strlen(a);

        for(i = 1; i <= (n+1)/2; i++) {
            if(a[0] == a[i] && (0 == n % i) && (r = check_period_str(a, i))) {
                printf("%d\n", r);
                //printf("dddd\n");
                break;
            }
        }
        if(i > (n+1)/2) printf("none 0\n");
    }

#ifdef LOCAL
    fclose(fin);
    fclose(fout);
#endif

    return 0;
}

