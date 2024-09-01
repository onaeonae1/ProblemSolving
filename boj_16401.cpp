#include<iostream>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, M; //먹일 입의 수, 과자의 수
	vector<int> items;
	cin >> N >> M;
	
	int start = 1;
	int end = 0;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		items.push_back(temp);
		end = (end < temp) ? temp : end;
	}
	
	while (start <= end) {
		int target = (start + end) / 2;
		int cnt = 0;
		if (target == 0) {
			ans = 0;
			break;
		}
		for (int i = 0; i < M; i++) {
			cnt += items[i] / target;
		}
		if (cnt >= N) {
			ans = (ans <= target) ? target : ans;
			start = target + 1;
		}
		else {
			end = target - 1;
		}
	}

	cout << ans << "\n";
	return 0;
}
