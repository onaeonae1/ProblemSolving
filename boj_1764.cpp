#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	map<string, int> items;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		items.insert({ t, 1 });
	}
	vector<string> ret;
	for (int i = 0; i < M; i++) {
		string t;
		cin >> t;
		if (items.find(t) != items.end()) {
			ret.push_back(t);
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (string t : ret) {
		cout << t << "\n";
	}

	return 0;
}
