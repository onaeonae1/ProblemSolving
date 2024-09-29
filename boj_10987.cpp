#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s) {
		if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u') {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
