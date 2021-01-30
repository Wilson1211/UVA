#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    vector<string> out;
    //string first, second, comment;
    char ss[185], first[85], second[85],comment[85];
    int index;
    int f_max = 0, snd_max = 0, forth_max = 0;
    char *ph;

    while(cin.getline(ss, 185) && ss[0] != '\n'){
    //cin.getline(ss, 185);
        f_max = 0; snd_max = 0;forth_max = 0;
        first[0] = '\n'; second[0] = '\n'; comment[0] = '\n';
        // if ss is char[185], first, second, comment are also char[]
        //index1 = strchr(ss, ':');
        //index2 = strchr(ss, '\\');
        sscanf(ss,"%s %s", first, second);
        //cout<<first << " " << second <<" "<<comment<<endl;
        f_max = max(f_max, (int)strlen(first));
        f_max++;
        snd_max = max(snd_max, (int)strlen(second));
        snd_max++;

        index = strchr(ss, '/')-ss;
        while(ss[index] == ' ') index++;
        strcpy(comment, ss+index);
        forth_max = max(forth_max, (int)strlen(comment));
        
        out.push_back(first);
        out.push_back(second);
        out.push_back(comment);
    }
        // print 

    for(int i=0;i<out.size();i+=3){

        
        cout<<out[i];
        for(int i=0;i<f_max-(int)strlen(out[i].c_str());i++) cout<<" ";
        cout<<out[i+1];
        for(int i=0;i<snd_max-(int)strlen(out[i+1].c_str());i++) cout<<" ";
        cout<<"// ";
        cout<<out[i+2]<<endl;
    }
    

    



    return 0;
}