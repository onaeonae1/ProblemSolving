#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		vector<int> A(50);
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			int t = c - 'A';
			A[t]++;
		}
		int sum = 0;
		int start = 0;
		int end = (int)'Z' - (int)'A';
		for (int i = start; i <= end; i++) {
			if (A[i] == 0) {
				sum += i + (int)'A';
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
