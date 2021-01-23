#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>


using namespace std;

string to_standard(string &s) { // tolower & sorted string
    string ss(s);
    for(int i = 0; i < ss.length(); i++) ss[i] = tolower(ss[i]);
    sort(ss.begin(), ss.end());
    return ss;
}

int main() {
    int i, j, k;
    string str, buf, tmp;
    map<string, int> mm;
    vector<string> stt;
    vector<string> ans;
    while(cin >> str) {
        if(str == "#") break;
        stringstream ss(str);
        while(ss >> tmp) {
            buf = to_standard(tmp);
            if(!mm.count(buf)) {
                mm[buf] = 1;
                stt.push_back(str);
            }
            else mm[buf]++; 
        }
    }
    map<string, int>::iterator it;
    for(i = 0; i < stt.size(); i++) 
        if(mm[to_standard(stt[i])] == 1) ans.push_back(stt[i]);
    sort(ans.begin(), ans.end());
    for(i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}