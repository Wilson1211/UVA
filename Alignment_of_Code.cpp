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
    char slash[] = "// ";
    vector<int> num;
    int index;
    int f_max = 0, snd_max = 0, forth_max = 0;
    char *ph;

    while(cin.getline(ss, 185) && strlen(ss)){

        first[0] = '\n'; second[0] = '\n'; comment[0] = '\n';
        // if ss is char[185], first, second, comment are also char[]
        //index1 = strchr(ss, ':');
        //index2 = strchr(ss, '\\');
        sscanf(ss,"%s %s", first, second);

        f_max = max(f_max, (int)strlen(first));

        snd_max = max(snd_max, (int)strlen(second));


        out.push_back(first);
        out.push_back(second);

        ph = strchr(ss, '/');
        if(ph) {
            index = ph-ss;
            index+=2;
            while(ss[index] == ' ') index++;
            strcpy(comment, ss+index);
            forth_max = max(forth_max, (int)strlen(comment));
            
            out.push_back(slash);
            out.push_back(comment);
            num.push_back(4);
        }else{
            num.push_back(2);
        }
        //out.push_back(enter);

    }
        // print 

  
    int i=0, j=0;
    
    while(i<out.size()){
        
        cout<<out[i];
        for(int k=0;k<=f_max-(int)strlen(out[i].c_str());k++) cout<<" ";
        cout<<out[i+1];
        for(int k=0;k<=snd_max-(int)strlen(out[i+1].c_str());k++) cout<<" ";

        if(num[j]-2){
            cout<<slash;
            cout<<out[i+3];
        }
        i+= num[j];
        j++;
        cout<<endl;
    }
    

    



    return 0;
}