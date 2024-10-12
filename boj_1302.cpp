#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string, int> items;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string ret="{";
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		if (items.find(t) == items.end()) {
			items[t] = 1;
		}
		else {
			items[t]++;
		}
		
		int cnt = items[t];
		if (cnt > ans) {
			// 무조건 갱신
			ans = cnt;
			ret = t;
		}
		else if (cnt == ans) {
			// 글자 사전순으로 확인
			int q = ret.compare(t);
			if (q > 0) {
				ret = t;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}
