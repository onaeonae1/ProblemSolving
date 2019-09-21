#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getPi(string message) { //pi 배열 구해줌
	int m = message.size();
	int j = 0;
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (message[begin + matched] == message[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1]; 
			}
		}
	}
	return pi;
}
vector<int> getRes(string message, string key) { //A에서 key에 대해 탐색
	vector<int> ret;
	vector<int> pi = getPi(key);
	int matched = 0;
	int n = message.size();
	int m = key.size();
	for (int i = 0; i < n; i++) {
		while (matched > 0 && message[i] != key[matched]) {
			matched = pi[matched - 1];
		}
		if (message[i] == key[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
void SWAP(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
int GCD(int a, int b){ //기약 분수로 만들기
	if (a < b) {
		SWAP(a, b);
	}
	while (b != 0){
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main() {
	string message; //전체 문자열
	string key; //구할 문자열
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char alpha;
		cin >> alpha;
		message.push_back(alpha);
	}
	for (int i = 0; i < N; i++) {
		char beta;
		cin >> beta;
		key.push_back(beta);
	}
	key += key; //원형 문자열이므로 2배로 늘려주고 탐색
	key.pop_back(); //하지만 맨 끝의 요소는 제거해준다. -> 똑같은거 2번이상 탐색 가능
	int count = getRes(key, message).size(); //2배로 늘려준 key에서 message를 탐색. 그리고 그 결과 리턴
	int div = GCD(count, message.size());
	cout << count/div << "/" << message.size()/div << endl;
	return 0;
}
