#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void addr_parse(string &s, string &user, string &mta){

    int index;
    index = s.find("@");
    user = s.substr(0,index);
    mta = s.substr(index+1);
}


int main() {

    string s, k;
    string src;
    string dest;
    int t;
    string user1, user2, mta1, mta2;
    map<string, set<string>> mtas;
    
    while(cin >> s && s != "*") {
        cin >> s >> t; // s is mta

        while(t--) { 
            cin >> k;   // k is user
            if(!mtas.find(s)){
                mta[s] = set<string>();
                mta[s].insert(k);
            }
        }
    }

    while(cin >> s && s != "*") {
        
        map<string, vector<string>> dess; // mta, users
        vector<string> mta; // store received mta
        set<string> vis; // store user

        addr_parse(s, user1, mta1);    

        while(cin >> k && k != "*") {
            addr_parse(k, user2, mta2);
            if(!vis.count(user2)) {
                vis.push_back(user2);
            }
            if(!dess.find(mta1)){
                mta.push_back(mta1);
                dess[mta1] = vector<string>();
                dess[mta1].push_back(user2);
            }
        }
        getline(cin, s); // eat *


        string data;
        while(getline(cin, s) && s[0] != "*"){
            data += ("    "+ s + "\n");
        }


        // print result
        
        for(int i=0;i<mta.size();i++){
            
            vector<string> users = dess[mta2];
            bool ok = false;

            cout <<"Connection between "<<mta1<<" and "<<mta2<<endl;
            cout << "HELO "<<mta1<<endl;cout<<"250"<<endl;
            if(!mtas[mta1].find) cout<<"550\n";
            cout<<"MAIL FROM:<"<<user1<<"@"<<mta1<<">"<<endl;
            
            for(int i=0;i<users.size();i++){
                
                cout<<"RCPT TO:<"<<  <<"@"<< << ">"<<endl;
                if(!mtas[mta2].find(users[i])) {
                    cout<<"250\n";
                    ok = true;
                }
                else cout<<"550\n";
            }
            if(ok) {
                cout<<"DATA\n"<<"354\n";
                cout<<data;
                cout<<endl;
                cout<<"250\n";
            }
            cout<<"QUIT"
            cout<<"221\n";
        }


    }




}