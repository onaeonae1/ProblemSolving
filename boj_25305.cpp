#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	priority_queue<int, vector<int>, less<int>> pq;
	for(int i=0; i<N; i++){
		int t;
		cin >> t;
		pq.push(t);
	}
	int cnt = 0;
	int ret = 0;
	while(!pq.empty() && cnt <M){
		int t= pq.top();
		pq.pop();
		ret = t;
		cnt++;
	}
	cout << ret << "\n";
	return 0;
}
