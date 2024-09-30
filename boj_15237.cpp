#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
struct Node{
    int occur=0;
    int num;
    int fidx;
};
map<string, Node> board;
vector<Node> items;
bool compare(const Node& a, const Node & b){
    if(a.occur == b.occur){
        return a.fidx < b.fidx;
    }
    else{
        return a.occur > b.occur;
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false); 
    int N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++){
        int q;
        cin >> q;
        string t = to_string(q);
        if(board.find(t)!=board.end()){
            Node& it = board[t];
            it.occur++;
        }
        else{
            board[t] = {1,q,i};
        }
    }
    for(auto iter = board.begin(); iter!=board.end(); iter++){
        Node t = iter->second;
        items.push_back(t);
    }
    sort(items.begin(), items.end(), compare);
    for(int i=0; i<items.size(); i++){
        int num = items[i].num;
        int occur = items[i].occur;
        for(int j=0; j<occur; j++){
            cout << num<< " ";
        }
    }
    return 0;
}
