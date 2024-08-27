#include<iostream>
using namespace std;
int ret = 0;
int n;
int board[15]; //board[i]=j : i번째 y에서 x는 j에 위치함;

int do_check(int nextY) {
	// 같은 xPos or cross
	for (int i = 0; i < nextY; i++) {
		bool sameX = (board[nextY] == board[i]);
		bool sameCross = ((nextY - i) == abs(board[nextY] - board[i]));
		if (sameX || sameCross) {
			return 0;
		}
	}
	return 1;
}

void nqueen(int ypos) {
	if (ypos == n) {
		ret++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[ypos] = i;
		if (do_check(ypos)==1) { 
			// do_check 가 안되면 가지치기, 되면 계속 이동
			nqueen(ypos + 1); 
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	nqueen(0);
	cout << ret << endl;
	return 0;

}
