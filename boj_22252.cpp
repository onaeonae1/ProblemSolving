#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main() {
	int cnt = 0;
	int N;

	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;

	map<string, int> dict;
	vector<priority_queue<int, vector<int>, less<int>>> items(N, priority_queue<int, vector<int>, less<int>>());
	
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int action; //1-> 고릴라 2-> 주인공
		int t;
		string key;
		cin >> action >> key >> t;

		if (dict.find(key) == dict.end()) {
			// 못찾았으므로 등록
			dict.insert({ key, ++cnt });
		}

		int targetIdx = dict[key];
		if (action == 1) {
			// 고릴라
			for (int j = 0; j < t; j++) {
				// j개 만큼 입력받아서 추가함
				int temp;
				cin >> temp;
				items[targetIdx].push(temp);
			}
		}
		else {
			// 나의 구매 -> t만큼 pop
			for (int i = 0; i < t; i++) {
				if (!items[targetIdx].empty()) {
					int value = items[targetIdx].top();
					ans += value;
					items[targetIdx].pop();
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
