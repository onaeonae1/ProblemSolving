#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getPi(string name) { //pi 배열 구해줌
	int m = name.size();
	int j = 0;
	vector<int> pi(m + 1, 0);
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
int getRes(string message, string reverse) { //겹치는 부분의 최대 출력
	vector<int> pi = getPi(reverse);
	int i = 0; int j = 0;
	//message의 접미사와 reverse의 접두사 비교
	while (i < message.size()) {
		if (j < reverse.size() && message[i + j] == reverse[j]) {
			j++;
			if (i + j == message.size()) {
				return j;
			}
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				i += j - pi[j - 1];
				j = pi[j - 1];
			}
		}
	}
	return 0;
}
int main() {
	int c;
	int results[55] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		string message; string reverse;
		cin >> message;
		for (int i = message.size()-1; i >=0; i--) {
			reverse.push_back(message[i]);
		}
		//결과값은 message.size() + reverse.size() - 겹치는 부분
		results[index] = (message.size() + reverse.size()) - getRes(message, reverse);
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
