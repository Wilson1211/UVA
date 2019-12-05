//#define LOCAL


int main() {

#ifdef LOCAL
    FILE *fin, *fout;
    fin = fopen("_input.txt", "r");
    fout = fopen("output.txt", "w");
#endif




#ifdef LOCAL
    fclose(fin);
    fclose(fout);
#endif

    return 0;
}
