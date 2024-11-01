#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

vector<int> positive;
vector<int> non_positive;
deque<int> p_deque; 
deque<int> np_deque;
int main(){
	ios_base::sync_with_stdio(0); 
  cin.tie(0);
	int N; 
  cin >> N;
	for(int i=0; i<N; i++){
		int t; 
    cin >> t;
		if(t > 0) {
        positive.push_back(t);
    }
		else non_positive.push_back(t);
	}
    sort(positive.begin(), positive.end(), greater<int>());
    sort(non_positive.begin(), non_positive.end());

	for(int i=0; i<positive.size(); i++){
		if(i & 1) {
          p_deque.push_back(positive[i]);
      }
		else{
          p_deque.push_front(positive[i]);
      } 
	}
	for(int i=0; i<non_positive.size(); i++){
		if(i & 1) {
          np_deque.push_back(non_positive[i]);
      }
		else {
          np_deque.push_front(non_positive[i]);
      }
	}
	if(!p_deque.empty() && p_deque.front() > p_deque.back()) {
        reverse(p_deque.begin(), p_deque.end());
    }
    if(!np_deque.empty() && np_deque.front() > np_deque.back()){
        reverse(np_deque.begin(), np_deque.end());
    }

    for(auto i : np_deque){
        cout << i << " ";
    }
    for(auto i: p_deque){
        cout << i << " ";
    }
    return 0;
}
