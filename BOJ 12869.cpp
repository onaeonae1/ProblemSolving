#include<iostream>
#include<vector>
#include<cstring>
#define X 99999999
using namespace std;
int DP[70][70][70]; // DP 테이블
int min(int a, int b) {
	if (a <= b) { return a;}
	else { return b; }
}
int max(int a, int b) {
	if (a >= b) { return a;}
	else { return b; }
}
int engine(int A, int B, int C) {
	//공격1 : 9
	//공격2 : 3
	//공격3 : 1
	if (A == 0 && B == 0 && C == 0) {
		return 0;
	}
	int& ret = DP[A][B][C]; //DP reference
	if (ret != -1) {
		return ret;
	}
	ret = X;
	// 1, 3, 9 가능한 경우를 모두 때려본다.
	ret = min(ret, engine(max(0, A - 9), max(0, B - 3), max(0, C - 1)) + 1);
	ret = min(ret, engine(max(0, A - 9), max(0, B - 1), max(0, C - 3)) + 1);
	ret = min(ret, engine(max(0, A - 3), max(0, B - 9), max(0, C - 1)) + 1);
	ret = min(ret, engine(max(0, A - 3), max(0, B - 1), max(0, C - 9)) + 1);
	ret = min(ret, engine(max(0, A - 1), max(0, B - 9), max(0, C - 3)) + 1);
	ret = min(ret, engine(max(0, A - 1), max(0, B - 3), max(0, C - 9)) + 1);
	return ret;
}
int main() {
	memset(DP, -1, sizeof(DP)); //DP 테이블 초기화
	int n;
	vector<int> scv;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		scv.push_back(value);
	}
	scv.push_back(0);
	scv.push_back(0);
	int result = engine(scv.at(0), scv.at(1), scv.at(2));
	cout << result << endl;
	return 0;
}
