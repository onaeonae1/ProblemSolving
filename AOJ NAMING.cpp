#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getPi(string name) { //pi 배열 구해줌
	int m = name.size();
	int j = 0;
	vector<int> pi(m+1, 0);
	for (int i = 1; i <= m; i++) {
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
vector<int> getRes(string name) { //pi 배열을 통해 접미사 접두사 일치 구해줌
	vector<int> result;
	vector<int> pi = getPi(name);
	int n = name.size(); //문자열 자신은 자신의 접미사, 접두사 모두 가능하므로
	while (n > 0) {
		result.push_back(n);
		n = pi[n - 1];
	}
	return result;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string N1; string N2;
	cin >> N1; cin >> N2;
	string name = N1 + N2;
	vector<int> result = getRes(name);
	while (result.empty() == false) {
		int value = result.back();
		result.pop_back();
		cout << value << " ";
	}
	return 0;
}
