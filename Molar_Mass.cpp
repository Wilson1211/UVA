#include <stdio.h>
#include <ctype.h>
#include <string.h>

double cal_mass(char *c) {
    switch (*c)
    {
    case 'C'/* constant-expression */:
        return 12.01;
        break;
    case 'H' :
        return 1.008;
        break;
    case 'O' :
        return 16.00;
        break;
    case 'N' :
        return 14.01;
        break;
    default:
        break;
    }
    return 0;
}

int main() {

    double sum = 0;
    char s[1005];
    int i, n;
    int T;

   
    // Debug
    FILE *fin, *fout;
    fin = fopen("Molar_Mass_input.txt", "r");
    fout = fopen("output.txt", "w");


    int adder = 0;
    double multi = 0;

    
    //fscanf(fin, "%d", &T);
    scanf("%d", &T);

    while(T--) {
        //fscanf(fin, "%s", s);
        scanf("%s", s);
        n = strlen(s);
        /*
        for(i = 0; i < n-1; i++) {
            if(isalpha(s[i]) && !isalpha(s[i+1])) sum += cal_mass(&s[i]) * (s[i++] - '0');   
            else sum += cal_mass(&s[i]);
        }
        if(isalpha(s[n-1])) sum += cal_mass(&s[n-1]);
        */
    
        for(i = 0; i < n; i++) {

            if(isalpha(s[i])) {
                if(adder != 0) sum += multi * adder;
                else {sum += multi;}
                multi = cal_mass(&s[i]);
                adder = 0;
            }
            else {
                adder *= 10;
                adder += (s[i] - '0');
            }
        }
        if(isalpha(s[n-1])) {
            sum += multi;
            multi = 0;
        }
        else {
            sum += multi * adder;
            multi = 0;
            adder = 0;
        }
        printf("%.3f\n", sum);
        //fprintf(fout, "%.3f\n", sum);
        sum = 0;
    }




    return 0;
} 