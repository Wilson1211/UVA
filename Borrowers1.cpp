//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=50&page=show_problem&problem=166
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOR1(i,a,b) for(int i=a;i<=b;++i)
#define INVFOR(i,a,b) for(int i=a;i>b;--i)
#define INVFOR1(i,a,b) for(int i=a;i>=b;--i)
#define SZ(i) int(i.size())
#define eb emplace_back
#define pb pop_back
#define ALL(i) i.begin(),i.end()
#define X first
#define Y second

vector<string> lib;
vector<int> borrowed;
map<string, int> ID;
vector<string> Books;
void setID(){
    string tmp1, tmp2;
    int k;
    FOR(i, 0, lib.size()){
        tmp1 = lib[i];
        k = tmp1.find('_');
        tmp2 = tmp1.substr(k+1);
        ID.insert(make_pair(tmp2, i));
        Books.eb(tmp2);
    }
    // check
    // cout<<"Books\n";
    // FOR(i, 0, Books.size()){
    //     cout<<Books[i];
    // }
    // cout<<endl;
}

int getID(string &title){
    return ID[title];
}

int main() {

    string book;
    string author;
    string title;
    while(getline(cin, book)&&(book!="END")){
        int k;
        k = book.find(" by ");
        title = book.substr(0,k);
        author = book.substr(k+4);
        lib.eb(author+"_"+title);
    }

    sort(lib.begin(), lib.end());
    borrowed.resize(lib.size(), 0);
    setID();
    string tmp1;
    int k1;
    vector<int> returned;
    while(getline(cin, book)&&(book!="END")){
        //cout<<book<<" here\n";
        if(book[0]=='B'){
            k1 = book.find(" ");
            tmp1= book.substr(k1+1);
        
            int id = getID(tmp1);
            borrowed[id] = 1;
        }else if(book[0]=='R'){
            k1 = book.find(" ");
            // cout<<book<<" here\n";
            // cout<<"k1: "<<k1<<endl;
            tmp1= book.substr(k1+1);
        
            int id = getID(tmp1);
            returned.eb(id);

        }else{ // shelved
            // FOR(i, 0, returned.size()){
            //     cout<<returned[i]<<" ";
            // }
            // cout<<endl;
            sort(returned.begin(), returned.end());
            int id;
            FOR(i, 0, returned.size()){
                id = returned[i];
                borrowed[id] = 0; 
                string pre_book="";
                INVFOR1(j, id-1, 0){
                    if(borrowed[j]==0){
                        pre_book=Books[j];
                        break;
                    }
                }
                if(pre_book.length()>0){
                    cout<<"Put "<<Books[id]<< " after "<< pre_book<<endl;
                }else{
                    cout<<"Put "<<Books[id]<<" first"<<endl;
                }
            
            }
            cout<<"END\n"; 
            returned.clear();
        }
    }

    return 0;
}