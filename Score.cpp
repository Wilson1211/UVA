#include <stdio.h>
#include <string.h>
#define maxn 85
int main() {

    int i, count = 1, ans = 0, T, n;
    char s[maxn];

    FILE *fin, *fout;
    fin = fopen("Score_input.txt", "r");
    fout = fopen("output.txt", "w");

    //scanf("%s", s);
    fscanf(fin, "%d", &T);
    
    while(T--) {
        fscanf(fin, "%s", s);
        n = strlen(s);
        count = 1;
        ans = 0;
        for(i = 0; i < n; i++) {
            if(s[i] == 'X') count = 0;
            ans += count;
            count++;
        }
        //printf("%d\n", ans);
        fprintf(fout, "%d\n", ans);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}