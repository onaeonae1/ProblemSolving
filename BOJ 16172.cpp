#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getPi(string key) {
	int n = key.size();
	vector<int> pi(n+1, 0);
	int now = -1;
	int idx = 0; 
	pi[idx] = now;
	while (idx < n) {
		if (now == -1 || (now >= 0 && key[now] == key[idx])) {
			now++;
			idx++;
			pi[idx] = now;
		}
		else {
			now = pi[now];
		}
	}
	return pi;
}

string subStr(string raw) {
	string temp;
	char st = '0';
	char ed = '9';
	for (int i = 0; i < raw.size(); i++) {
		if (raw.at(i) < st || raw.at(i) > ed) {
			temp.push_back(raw.at(i));
		}
	}
	return temp;
	
}
int searchKMP(string text, string key) {
	int n = text.size();
	int m = key.size();
	vector<int> pi = getPi(key);
	int flag = 0;
	int now = 0;
	int idx = 0;
	while (idx < n) {
		if (now == -1 || (now >= 0 && text[idx] == key[now])) {
			idx++;
			now++;
		}
		else if (text[idx] != key[now]) {
			now = pi[now];
		}
		if (now == m) {
			flag = 1;
			now = pi[now];
			break;
		}
	}
	return flag;
}
int main() {
    	ios::sync_with_stdio(false);
	cin.tie(0);
	string text;
	string pattern;
	cin >> text;
	cin >> pattern;
	text = subStr(text);
	int result = searchKMP(text, pattern);
	printf("%d", result);
	return 0;
}
