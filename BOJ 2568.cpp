#include<iostream>
#include<vector>
#include<algorithm>
#define L 100001
using namespace std;
vector<pair<int, int>> bridge; //시작 - 끝 저장
int dp[L];
pair<int, int> tracking[L]; //list에서의 인덱스와 다리에서의 시작 위치 저장
bool check[5 * L];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int max = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		bridge.push_back(make_pair(start, end));
		check[start] = true;
		if (start > max) {
			max = start;
		}
	}
	sort(bridge.begin(), bridge.end()); //오름차순으로 정렬(시작점 기준)
	dp[0] = bridge.at(0).second;
	tracking[0] = make_pair(0, bridge.at(0).first);
	int idx = 0; 
	for (int i = 1; i < n; i++) {
		int refi = bridge.at(i).first;
		int ref = bridge.at(i).second;
		int now = dp[idx];
		if (now < ref) {
			dp[++idx] = ref;
			tracking[i] = make_pair(idx, refi);
		}
		else {
			int ii = lower_bound(dp, dp + idx, ref) - dp;
			dp[ii] = ref;
			tracking[i] = make_pair(ii, refi);
		}
	}
	vector<int> removelist;
	cout << n - idx- 1 << "\n";
	for (int i = n-1; i >= 0; i--) {
		if (tracking[i].first == idx) { //사용함
			removelist.push_back(tracking[i].second);
			idx--;
		}
	}
	while (!removelist.empty()) {
		check[removelist.back()] = false;
		removelist.pop_back();
	}
	for (int i = 0; i <= max; i++) {
		if (check[i] == true) {
			cout << i << "\n";
		}
	}
	return 0;
}
