#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int N;
string S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	cin >> N;
	vector<pair<string, double>>items;
	for (int i = 0; i < N; i++) {
		string temp;
		int g;
		cin >> temp >> g;
		int idx = 0, cnt = 0, sidx = 0;
		double score = 0;
		if (S.length() <= temp.length()) {
			for (int j = idx; sidx != S.length() && j < temp.length(); j++) {
				if (S[sidx] == temp[j] && sidx != S.length()) {
					idx = j + 1;
					sidx++;
					if (sidx == S.length()) {
						cnt += (temp.length() - 1) - j;
					}
				}
				else {
					cnt++;
				}
			}
		}
		if (sidx == S.length()) {
			score = (double)g / (double)cnt;
			items.push_back({ temp,score });
		}
		else {
			items.push_back({ temp, 0 });
		}
	}
	double res = 0;
	string ret = "No Jam";
	for (int i = 0; i < items.size(); i++) {
		if (res < items[i].second) {
			res = items[i].second;
			ret = items[i].first;
		}
	}
	cout << ret << "\n";
	return 0;
}
