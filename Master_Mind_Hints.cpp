#include <stdio.h>
#define maxn 1010

int main(){
    int ans[maxn] = {};
    int comp[10] = {};
    int test[maxn] = {};
    int comp_test[10] = {};
    int i, c1, c2, m, count = 0, n;

    //FILE *fin, *fout;
    //fin = fopen("Master_Mind_hints_input.txt", "r");
    //fout = fopen("output.txt", "w");


    while(scanf("%d", &n) == 1 && n){
    //while(fscanf(fin,"%d", &n) == 1 && n){
        printf("Game %d:\n", ++count);
        
        // preprocess comp & comp_test
        for(i = 1; i < 10; i++) comp[i] = comp_test[i] = 0;

        for(i = 0; i < n; i++){
            scanf("%d",&ans[i]);
            //fscanf(fin, "%d",&ans[i]);
            comp[ans[i]]++;
        }

        while(1){
            
            //preprocessing of comp_test
            for(i = 0; i < 10; i++) comp_test[i] = 0;

            c1 = c2 = m = 0;
            for(i = 0; i < n; i++){
                scanf("%d",&test[i]);
                //fscanf(fin, "%d",&test[i]);
                //if(test[i] == 0) break;
                comp_test[test[i]]++;
                if(ans[i] == test[i]) c1++;

            }
            if(test[0] == 0) break;
            for(i = 1; i < 10; i++){
                c2 += (comp[i] < comp_test[i])?comp[i]:comp_test[i];
            }
            c2  = (c2 > c1)?c2-c1:0;
            printf("(%d,%d)\n", c1, c2);   
            //fprintf(fout, "    (%d,%d)\n", c1, c2);
        }
    }
    //fclose(fin);
    //fclose(fout);
    return 0;
}