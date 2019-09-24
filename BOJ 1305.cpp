#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getPi(string name) { //pi 배열 구해줌
	int m = name.size();
	int j = 0;
	vector<int> pi(m + 1, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && (name[i] != name[j])) {
			j = pi[j - 1];
		}
		if (name[i] == name[j]) {
			j++;
			pi[i] = j;
		}
	}
	return pi;
}
int main() {
	int n;
	cin >> n;
	string message;
	cin >> message;
	vector<int> pi = getPi(message);
	int res = message.size() - pi.at(message.size() - 1);
	cout << res << endl;
	return 0;
}
