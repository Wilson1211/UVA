#include <stdio.h>

#include <string.h>

int code[8][1<<8] = {};

int readcodes() {
    char ch;
    ch = getchar();
    code[1][0] = ch;
    int j = 2;
    if (ch == EOF) return 0;
    for(;;) {
        for(int i = 0; i < 8; i++) {        
            ch = getchar();
            if(ch == EOF) break;
            code[j][i] = ch;
        }
        j++;
        if (ch == EOF) break;
    }
    return 1;
}

int readint(int len) {

    char ch;
    int ret = 0;
    while(len--) {
        ch = getchar();
        ret = ret * 2 + ch - '0';
    }

    return ret;
}

int main() {
    int v, len;
    while(readcodes()) {
        for(;;) {
            len = readint(3);
            if(len == 0) break;
            v = readint(len);
            if(v == (1<<(len-1))) break;
            putchar(code[len][v]);
        }
    }





    return 0;
}