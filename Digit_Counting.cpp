#include <stdio.h>
#include <string.h>
//#include <string>

long int chuck_front(long int &num, int k) {
    long int i = 10;
    while(k--) i *= 10;
    return (num / i);
}

long int chuck_back(long int &num, int k) {
    int i;
    long int r = 1;
    for(i = 0; i < k; i++) r *= 10;
    return num % r;
}


void cal(long int *c, long int &num, int k) {
    
    int i, cc = 1;
    long int front, back;
    front = chuck_front(num, k);
    back = chuck_back(num, k);
    //printf("front: %ld\n",front);
    //printf("back: %ld\n", back);

    while(k--) cc *= 10; // 1 << 10
    long int nn = num / cc;//>> k;
    int small = nn % 10;
    if(front != 0) for(i = 0; i < small; i++) c[i] += (front + 1) * cc;
    else for(i = 1; i < small; i++) c[i] += (front + 1) * cc;
    c[i++] += (front * cc + (1) * (back + 1));
    if(front != 0) {
        for(; i < 10; i++) c[i] += (front) * cc;
    }
}

int main() {
    int T, i;
    long int num, nn;
    long int c[10] = {};
    long int count = 0;

    //FILE *fin, *fout;
    //fin = fopen("Digit_Counting_input.txt", "r");
    //fout = fopen("output.txt", "w");
    scanf("%d", &T);
    //fscanf(fin, "%d", &T);
    while(T--) {
        scanf("%ld", &num);
        //fscanf(fin, "%ld", &num);
        for(i = 0; i < 10; i++) c[i] = 0;
        count = 0;
        nn = num;
        while(nn != 0) {
            nn /= 10;
            cal(c, num, count);// bug    
            count++; 
        }
        if(count != 1) c[0]--;
        if(count > 2) c[0] -= 10;
        for(i = 0; i < 9; i++) printf("%ld ", c[i]);
        printf("%ld", c[9]);
        printf("\n");
        
        //for(i = 0; i < 10; i++) fprintf(fout, "%ld ", c[i]);
        //fprintf(fout, "\n");
    }
    //fclose(fin);
    //fclose(fout);

    return 0;
}