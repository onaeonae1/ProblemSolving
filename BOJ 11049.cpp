#include<iostream>
#define LIM 999999999
#define L 505
using namespace std;
int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int board[L][L];
int matrix[L];
int N;
int main() {
	cin >> N;
	cin >> matrix[0]>> matrix[1];
	for (int i = 1; i < N - 1; i++) {
		cin >> matrix[i] >> matrix[i + 1];
	}
	cin >> matrix[N - 1]>> matrix[N];
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			int m = j + i;
			if (j == m) {
				board[j][m] = 0;
				continue;
			}
			board[j][m] = LIM;
			for (int k = j; k < m; k++) {
				board[j][m] = min(board[j][m], board[j][k] + board[k + 1][m] + matrix[j - 1] * matrix[k] * matrix[m]);
			}
		}
	}
	cout << board[1][N] << endl;
	return 0;
}
