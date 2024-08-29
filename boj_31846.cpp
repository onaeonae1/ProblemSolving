#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N, t;
string s;
vector<int> items;
int do_search(int start, int end) {
	int ans = 0;
	int m = start;
	for (int m = start; m < end; m++) {
		int cnt = 0;
		int right = m + 1;
		int left = m;
		while (right <= end && left >= start) {
			if (items[right] == items[left]) {
				cnt++;
			}
			right++;
			left--;
		}
		ans = (ans < cnt) ? cnt : ans;
	}
	return ans;
}


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	cin >> s;
	items.push_back(0);
	for (char i : s) {
		items.push_back(int(i));
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int start, end;
		cin >> start >> end;
		cout << do_search(start, end) << "\n";
	}

	return 0;
}
