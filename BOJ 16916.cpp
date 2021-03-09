#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> getPi(string pattern) {
	int m = pattern.size();
	int j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
vector<int> kmp(string str, string pattern) {
	vector<int> ans;
	vector<int> pi = getPi(pattern);
	int n = str.size();
	int m = pattern.size();
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (str[i] == pattern[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string message, pattern;
	cin >> message;
	cin >> pattern;
	vector<int> ans = kmp(message, pattern);
	if (ans.size()) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
