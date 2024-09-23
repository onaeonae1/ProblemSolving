#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string s, q;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		q.push_back(s[i]);
		if (q.size() >= 2) {
			int j = q.size()-1;
			if (q[j] == '4' || q[j] == '5') {
				if (q[j - 1] == 'S' && q[j - 2] == 'P') {
					q.pop_back();
				}
			}
		}
	}
	cout << q;
	return 0;
}
