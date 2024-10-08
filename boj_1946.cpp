#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		vector<pair<int, int>> items;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			items.push_back({ a,b });
		}
		sort(items.begin(), items.end(), compare);
		int maxV = items[0].second;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int temp = items[i].second;
			if (temp <= maxV) { // 넌 의미가 있다
				ans++;
				maxV = temp;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
