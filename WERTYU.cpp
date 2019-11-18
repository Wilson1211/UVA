#include <stdlib.h>
#include <stdio.h>
int main(){
    
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    int c;
    while(( c = getchar()) != EOF){
        for(i=0;s[i] && s[i]!=c;i++);
        if(s[i]){
            //printf("%c",s[i-1]);
            putchar(s[i-1]);    
        }else{
            putchar(c);
        }
    }
    return 0;
}