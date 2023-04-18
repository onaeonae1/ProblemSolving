#include<iostream>
#include<string>
using namespace std;
int A[1000][1000];
int blueCount, whiteCount;
int n;
bool checkExceed(int sty, int stx) {
	bool isExceed = (sty > n || sty<0 || stx >n || stx < 0);
	return isExceed;
}
void solve(int sty, int stx, int val) {
	// 탈출 조건
	bool isExceed = checkExceed(sty, stx);
	if (isExceed) {
		return;
	}
	else if(val==1) {
		if (A[sty][stx] == 0) {
			whiteCount++;
		}
		else {
			blueCount++;
		}
		return;
	}
	// check if with same value
	int checker = -1;
	bool flag = true;
	for (int i = 0; (i < val) && flag; i++) {
		for (int j = 0; (j < val) && flag; j++) {
			int targetY = sty + i;
			int targetX = stx + j;
			int target = A[targetY][targetX];
			if (checker == -1) {
				checker = target;
			}
			else {
				if (checker != target) {
					checker = -1;
					flag = false;
				}
			}
		}
	}

	if (flag) {
		// 하나로 되어 있음이 맞다
		if (checker == 0) {
			whiteCount ++;
		}
		else if(checker==1) {
			blueCount ++;
		}
		return;
	}
	else {
		// 4분할 하시면 됩니다..
		int nextVal = val / 2;
		solve(sty, stx, nextVal);
		solve(sty, stx + nextVal, nextVal);
		solve(sty + nextVal, stx, nextVal);
		solve(sty+nextVal, stx + nextVal, nextVal);
		return; 
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	solve(1, 1, n);
	cout << whiteCount << endl;
	cout << blueCount << endl;
	return 0;
}
