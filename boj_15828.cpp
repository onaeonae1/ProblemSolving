#include<iostream>
#include<queue>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    queue<int> q;
    while(true){
        int t;
        cin >> t;
        if(t==0){
            if(!q.empty()){
             q.pop();   
            }
        }
        else if(t==-1){
            break;
        }
        else{
            if(q.size()<N){
                q.push(t);
            }
        }
    }
    if(q.empty()){
        cout << "empty";
    }
    while(!q.empty()){
        cout << q.front() <<" ";
        q.pop();
    }
    return 0;
}
