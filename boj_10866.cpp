#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main() {
	int N;
	cin.tie(0);
	cin.sync_with_stdio(false);
	deque<int> items;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		int t;
		cin >> s;
		if (s == "push_back" || s == "push_front") {
			// 숫자 따로 입력받아야 함
			cin >> t;
			if (s == "push_back") {
				items.push_back(t);
			}
			else {
				items.push_front(t);
			}
		}
		if (s == "pop_front" || s == "pop_back") {
			if (items.empty()) {
				cout << -1 << "\n";
			}
			else {
				if (s == "pop_front") {
					cout << items.front() << "\n";
					items.pop_front();
				}
				if (s == "pop_back") {
					cout << items.back() << "\n";
					items.pop_back();
				}
			}

		}
		if (s == "front") {
			if (!items.empty()) {
				cout << items.front() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		if (s == "back") {
			if (!items.empty()) {
				cout << items.back() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		if (s == "size") {
			cout << items.size() << "\n";
		}
		if (s == "empty") {
			if (!items.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
	}
	return 0;
}
