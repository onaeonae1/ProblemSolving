#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N, L;
int main(){
    cin.tie(0);
    cin >> N;
    N = N * 2 + 1;
    long long ans = 0;
    string s;
    vector<int> tempStack;
    vector<int> ansStack;
    cin >> L;
    cin >> s;
    for(int i=0; i<L; i++){
        int now = (s[i]=='I') ? 1 : 0;
        if(tempStack.empty()){
            if(now==1){
                tempStack.push_back(now);
            }
            else{
                continue;
            }
        }
        else if((tempStack.back()==0 && now ==1 ) || tempStack.back()==1 && now==0){
            tempStack.push_back(now);
        }
        else{
            ansStack.push_back(tempStack.size());
            tempStack.clear();
            if(now==1){
                tempStack.push_back(now);
            }
        }
        // cout << s[i] << tempStack.size() << "\n";
    }
    if(!tempStack.empty()){
        ansStack.push_back(tempStack.size());
    }
    for(auto i: ansStack){
        if(i>=N){
            ans += ((i-N) / 2 )+1;
        }
    }
    cout << ans <<"\n";
    return 0;
}
