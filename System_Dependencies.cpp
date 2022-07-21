//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=447

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


#define maxn 100005

class Node{
public:
    char name[81];
    vector<Node> parent;
}

Node collect[maxn];
queue<int> vailable_node;
int count_node;

int get_node(){
    int ret = -1;
    if(vailable_node.size()>0){
        ret = vailable_node.front(); vailable_node.pop();
    }
    return ret;
}

void node_insert(string item){
    if(mm_node.find(item)==mm_node.end()){
        int num = get_node();
        assert(num!=-1);
        strcpy(collect[num].name, item.c_str());
        return num;
    }else{
        return mm_node[item];
    }
}

void construct_node(string *input){
    stringstream ss(*input);
    string item;
    string child;
    vector<int> parent;
    int num;
    getline(ss, item, ' '); // Depend
    getline(ss, child, ' ');// child

    while(getline(ss, item, ' ')){
        node_insert(item);
    }
}

int main() {
    string input;
    while(getline(cin, input)&&(input!="END")){
        if(input[0]=='D'){
            construct_node(input);
        }else if(input[0]=='R'){
            
        }else if(input[0]=='I'){

        }else{ // List

        }
    }



    return 0;
}