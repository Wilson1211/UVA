//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=146
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


class prog{
public:
    prog(){}
    prog(int a, int b, int c)
        :id(a),index(b), quota
    {}
    void setp(int a){
        index = a;
    }
    int id; // program id
    int index; // cmd in the token
    int quota;
};

deque<prog> ready;//ready queue
queue<prog> lc;//lock queue
int a[26]; // represent variable

int n, t1, t2, t3, t4, t5, Q;
int lock = 0;
void command_time(vector<vector<string>> &command, vector<vector<int>> &time){
    int sz = command.size();
    FOR(z, 0, sz){
        string str;
        vector<int> tt;
        int sz2 = command[z].size();
        FOR(k, 0, sz2){
            str = command[z][k];
            size_t found = str.find(' ');
            string tmp = str.substr(0, found);
            if(tmp.length()==1){
                tt.eb(t1);
            }else if(tmp=="print"){
                tt.eb(t2);
            }else if(tmp=="lock"){
                tt.eb(t3);
            }else if(tmp=="unlock"){
                tt.eb(t4);
            }else{ // end
                tt.eb(t5);
            }
        }
        time.eb(tt);
    }
}

inline void process_lck(prog &program, int k){
    if(k==1){ // lock
        if(lock==1){
            lc.push_back(program);
        }else{
            lock=1;
        }
    }else{
        lock = 0;
        prog program = lc.pop();
        ready.push_front(program);
    }
}

inline void process_var(int id, strint str){
    string str1;
    size_t found;
    
    found = str.find(' ');
    str1 = str.substr(0, found);
    if(str1=="print"){
        str1 = str.substr(found+1);
        cout<<id<<": "<<a[str1-'a']<<endl;
    }else if(lock==0){ // assign value to var
        int index = str1-'a';
        str1 = str.substr(found+3);
        stringstream ss;
        ss << str1;
        int num;
        ss >> num;
        a[index] = num;
    }
}

int main() {

    vector<vector<string>> command;
    cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
    string str;
    cin.ignore();
    FOR(z, 0, n){
        vector<string> tmp;
        while(getline(cin, str)&&(str!="end")){
            tmp.eb(str);
        }
        command.eb(tmp);

        prog tt(z, 0, Q);
        ready.push(tt);
    }

    vector<vector<int>> time;// record each cmd time


    command_time(command, time);

    int count_end =0 ;
    while(count_end < n){
        string str;
        prog program = ready.pop_front;
        int index = program.index;
        int id = program.id;
        int quota = Q;
        while(quota>0){
            quota -= time[id][index];
            if(quota >= 0){ // this cmd can be excuted
                string str = command[id][index];
                if(str=="lock"){
                    process_lck(program, 1);
                    break;
                }else if(str == "unlock"){
                    process_lck(program, 0);
                }else if(str == "end"){
                    /* do nothing */
                }else{ // assign var or print
                    process_var(id, str);
                }

            }else{ // need to go back to ready queue
                time[id][index] = 0-quota;
                ready.push_back(program);
            }
        }
    }

    return 0;
}