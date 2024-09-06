#include<iostream>
#include<string>
char board[200005];
int DP[200005]; // DP[i]: i를 숫자로 취급할때의 최대값
using namespace std;
int get_max(int a, int b) {
	int ret = a;
	ret = (a < b) ? b : a;
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		board[i] = s.at(i);
		DP[i] = -1e9;		
	}
	
	DP[0] = (board[0] == '+') ? 10 : 1;
	DP[1] = ((board[0] == '+') && (board[1] == '-')) ? 11 : -1e9;
	int t1 = (board[0] == '+') ? 10 : 1;
	int t2 = (board[2] == '+') ? 10 : 1;
	DP[2] = (board[1] == '+') ? t1 + t2 : t1 - t2;
	for (int i = 3; i < n; i++) {
		int now = (board[i] == '+') ? 10 : 1;
		int direc = (board[i-1] == '+') ? 1 : -1;

		if (now == 10) {
			DP[i] = (DP[i - 2] != -1e9) ? get_max(DP[i], DP[i - 2] + 10 * direc) : DP[i];
		}
		else {
			DP[i] = (DP[i - 2] != -1e9) ? get_max(DP[i], DP[i - 2] + 1 * direc) : DP[i];

			if (i >= 3 && direc==1) {
				int newdirec = (board[i - 2] == '+') ? 1 : -1;
				DP[i] = (DP[i - 3] != -1e9) ? get_max(DP[i], DP[i - 3] + 11 * newdirec) : DP[i];

			}
		}
	}
	cout << DP[s.size()-1];
	return 0;
}
