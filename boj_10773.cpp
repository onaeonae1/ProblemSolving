#include<iostream>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int K;
	cin >> K;
	int sum = 0;
	vector<int> items;
	while (K--) {
		int t;
		cin >> t;
		if (t == 0) {
			if (!items.empty()) {
				items.pop_back();
			}
		}
		else {
			items.push_back(t);
		}
	}
	for (int i : items) {
		sum += i;
	}
	cout << sum;
	return 0;
}
