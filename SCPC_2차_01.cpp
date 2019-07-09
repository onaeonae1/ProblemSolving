#include<iostream>
#include<string>
using namespace std;
bool isNotPrime[30005];
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int div(string s) {
	int result = 0;
	int n = stoi(s); 
	//자기 자신 체크
	if (isNotPrime[n] == false) {
		result++;
	}
	//분해 필요 없음
	if (s.size() == 1) {
		return result;
	}
	//분해 필요
	else {
		int tempvalue = 0;
		for (int i = 0; i < s.size(); i++) {
			string part = s; //복사 떠주고
			part.erase(i,1);
			tempvalue = max(tempvalue, div(part));
		}
		result += tempvalue; //전체 분해 결과의 최대값을 더함
	}
	return result;
}
void PrimeSet() {
	for (int i = 2; i <= 30000; i++) {
		for (int j = i + i; j <= 30000; j+=i) {
			isNotPrime[j] = true;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	isNotPrime[0] = true;  isNotPrime[1] = true;
	PrimeSet(); //소수 처리해줌
	int c;
	int results[25] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		string N;
		string M;
		cin >> N >> M; //주는 숫자를 문자로 처리해준다.
		int alpha = div(N);
		int beta = div(M);
		if (alpha > beta) {
			results[index] = 1;
		}
		if (alpha < beta) {
			results[index] = 2;
		}
		if (alpha == beta) {
			results[index] = 3;
		}
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << "Case #" << i << endl;
		cout << results[i] << endl;
	}
	return 0;
}
