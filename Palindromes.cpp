#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
    const char* s = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    const char* msg[] = {"is not a palindrome.", "is a regular palindrome.", "is a mirrored string.", "is a mirrored palindrome."};

    //FILE *fin, *fout;
    //fin = fopen("Palindromes_input.txt", "r");
    //fout = fopen("output.txt", "w");

    int i, len;
    int p=1,m=1;
    char c[30];
    while(scanf("%s",c) == 1){
    //while(fscanf(fin,"%s", c) == 1){
        len = strlen(c);
        p=1;m=1;
        for(i = 0; i < (len + 1)/2; i++){
            if(c[i] != c[len-1-i]){p = 0;}
            if(isalpha(c[i])){
                if(c[len-1-i] != s[c[i]-'A']){m = 0;}
            }else{
                if(c[len-1-i] != s[c[i] - '0' + 25]){m = 0;}
            }
        }
        printf("%s -- %s\n\n", c, msg[m*2 + p]);
        //fprintf(fout, "%s -- %s\n\n", c, msg[m*2 + p]);
    }

    //fclose(fin);
    //fclose(fout);

    return 0;
}