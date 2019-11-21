#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 105
/*
bool less(char *s, int a, int b) {
    int i, n = strlen(s);
    for(i = 0; i < n; i++) 
        if(s[(a+i)%n] > s[(b+i)%n]) return 0;
        else if(s[(a+i)%n] < s[(b+i)%n]) return 1;
    return 0; // same
}
*/


bool less(char *s, int a, int b) {
    int i, n = strlen(s);
    for(i = 0; i < n; i++){
        if(s[(a+i)%n] != s[(b+i)%n]) 
            return s[(a+i)%n] < s[(b+i)%n];
    }
    return 0;// same
}

int main(){
    int i, n;
    char s[maxn];
    int T;
    
    //File debug
    /*
    FILE *fin, *fout;
    fin = fopen("Circular_Sequence_input.txt", "r");
    fout = fopen("output.txt", "w");
    */
    
    scanf("%d", &T);
    //fscanf(fin, "%d", &T);


    while(T--) {
        int ans = 0;
        scanf("%s", s);
        //fscanf(fin, "%s", s);
        n = strlen(s);
        for(i = 0; i < n; i++)
            if(less(s, i, ans)) ans = i;
        for(i = 0; i < n; i++)
            //fprintf(fout, "%c", s[(ans+i)%n]);
            putchar(s[(ans+i)%n]);
        putchar('\n');
        //fprintf(fout, "\n");
    }

    //fclose(fin);
    //fclose(fout);
    return 0;
}