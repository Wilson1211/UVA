// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=233

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
#define imp(i, j) insert(make_pair(i, j)) 
#define X first
#define Y second

#define maxn 512

class node{
public:
    node():black(0), ch_num(0){}
    int black;
    node* ch[4];
    int ch_num;
};

node Node[maxn];
int Node_idx; // Node[idx]
string str;
int str_idx;
int str_len;
int Node_cnt;

int ans[7];

queue<node*> emp;

void init(){
    FOR(i, 0, 64){
        Node[i].black = 0;
        Node[i].ch_num = 0;
        emp.push(&Node[i]);
    }
    FOR(i, 0, 7){
        ans[i] = 0;
    }
}

node* newnode(){
    node* tmp;
    tmp = emp.front();
    emp.pop();

    return tmp;
}
void traverse_tree(node *nnode, int level){
    if(nnode->black){
        ans[level]++;
    }else if(nnode->ch_num>0){
        FOR(i, 0, 4){
            traverse_tree(nnode->ch[i], level+1);
        }
    }
    return;
}

void construct_tree(node *parent, int chd){ // idx on the string
    if(Node_idx>=str_len) return;
    str_idx++;
    char color = str[str_idx];
    int ch_num;
    if(color=='p'){
        node *tmp;
        if(parent->ch_num<4){
            tmp = newnode();
            parent->ch[chd] = tmp;
            parent->ch_num++;
        }else{
            tmp = parent->ch[chd];
        }
        FOR(i, 0, 4){
            construct_tree(tmp, i);
        }
    }else if(color=='e'){
        node *tmp;
        if(parent->ch_num<4){
            tmp = newnode();
            parent->ch[chd] = tmp;
            parent->ch_num++;
        }
    }else if(color=='f'){
        node *tmp;
        if(parent->ch_num<4){
            tmp = newnode();
            parent->ch[chd] = tmp;
            parent->ch_num++;
        }else{
            tmp = parent->ch[chd];
        }
        tmp->black = 1;
    }
}

int main() {

    int N;
    cin >> N;
    int cnt = 0;
    node *root;
    string str1, str2;
    while(N--){
        cin >> str1;
        cin >> str2;

        init();

        str = str1;
        Node_cnt = 0;
        str_len = str1.length();
        str_idx = 0;
        root = newnode();
        if(str_len>1){
            FOR(i, 0, 4){
                construct_tree(root, i);
            }
        }

        str = str2;
        str_len = str2.length();
        str_idx = 0;
        if(str_len>1){
            FOR(i, 0, 4){
                construct_tree(root, i);
            }
        }

        traverse_tree(root, 0);

        int final_ans = 0;
        int calvg = 1024;
        FOR(i, 0, 6){
            final_ans += ans[i]*calvg;
            calvg>>=2;
            cout<<ans[i]<<" ";
        }
        cout<<"final ans: "<<final_ans<<endl;
    }

    return 0;
}