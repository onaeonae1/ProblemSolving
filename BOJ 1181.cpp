#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string &a, string &b) {
	if (a.size() != b.size()) {
		return a.size() > b.size();
	}
	else {
		return a > b;
	}
}
int main() {
	int n;
	vector<string> dict;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		dict.push_back(temp);
	}
	sort(dict.begin(), dict.end(), compare);
	vector<string>::iterator iter = dict.begin();
	string alpha = dict.back();
	dict.pop_back();
	cout << alpha << endl;
	while (dict.empty() == false) {
		string now = dict.back();
		if (alpha != now) { //같지 않다면 - > 중복 존재
			cout << now << endl;
			alpha = now;
		}
		dict.pop_back(); //뽑음
	}
	return 0;
}
