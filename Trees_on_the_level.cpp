//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=58
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

class Node{
public:
    Node (){}
    Node operator = (Node const &obj){
        Node A;
        A.index = obj.index;
        A.left_right = obj.left_right;
        return A;
    }
    string get_str(){
        return left_right;
    }
    int get_index(){
        return index;
    }
private:
    int index;
    string left_right;
};

map<string, int> tree;

int read_input(string str){
    stringstream ss;

    string str_num, lr;
    int num;
    size_t found = str.find(',');
    size_t left_found = str.find('(');
    size_t right_found = str.find(')');
    while(found != string::npos){
        ss.clear();
        str_num = str.substr(left_found+1, found-left_found-1);
        ss<< str_num;
        ss >> num;
        lr = str.substr(found+1, right_found-found-1);
        if(lr==""){
            lr = "root";
        }
        if(tree.find(lr)!=tree.end()){
            return 2;
        }
        tree.insert(make_pair(lr, num));

        found = str.find(',', found+1);
        left_found = str.find('(', left_found+1);
        right_found = str.find(')', right_found+1);
    }

    if(right_found==string::npos){
        return 1;
    }
    return 0;
}
vector<int> ans;
/*
void tree_traverse(Node* parent){
    if(ans.size()>= tree.size9()){
        return;
    }
    string str = parent.get_str()+"L";
    if(tree.find(str)!=tree.end()){
        ans.eb(tree[str].index);

    }
    str = parent.get_str()+"R";
    if(tree.find(str)!= tree.end()){
        
    }
}
*/
bool construct_tree(){
    ans.clear();
    string root;
    bool flag = 1;
    if(tree.find("root")==tree.end()){
        cout<<"not complete\n";
        flag = 0;
        return flag;
    }
    queue<string> que;
    que.push(root);
    ans.eb(tree["root"]);
    while(ans.size()<tree.size()){
        if(que.size()>0){
            string now = que.front();
            string str = now+"L";
            if(tree.find(str)!=tree.end()){
                ans.eb(tree[str]);
                que.push(str);
            }
            str = now+"R";
            if(tree.find(str)!= tree.end()){
                ans.eb(tree[str]);
                que.push(str);
            }

            que.pop();
        }
        if(que.size()==0){
            cout<<"not complete\n";
            flag = 0;
            break;
        }
    }
    if(flag==0) return flag;
    FOR(i, 0, ans.size()-1){
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1]<<endl;
    return flag;
}

int main() {


    int flag;
    string str;
    while(getline(cin, str)){
        flag = read_input(str);
        if(!flag){

            flag = construct_tree();
            tree.clear();
        }else if(flag == 2){
            cout<<"not complete\n";
            tree.clear();
        }
    }




}