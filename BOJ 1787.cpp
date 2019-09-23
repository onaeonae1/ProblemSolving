#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#define LIM 999999999
using namespace std;
vector<int> pi;
int table[1000005];
int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
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
int search(int index) {
	if (index < 0 || pi[index] == 0) {
		return LIM;
	}
	int& now = table[index];
	if (now != -1) {
		return now;
	}
	now = min(pi[index], search(pi[index] - 1));
	return now;
}
int main() {
	memset(table, -1, sizeof(table)); //DP 테이블 초기화
	long long int ret = 0;
	int n;
	cin >> n;
	string message;
	cin >> message;
	pi = getPi(message); //message에 대한 pi배열 초기화
	for (int i = 0; i < n; i++) {
		int value = search(i);
		if (value != LIM) {
			ret += (i - value + 1);
			test.push_back(i - value + 1);
		}
	}
	cout << ret << endl;
	return 0;
}
