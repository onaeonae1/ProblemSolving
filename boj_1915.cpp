#include<iostream>
#include<string>
using namespace std;
int board[1005][1005];
int N, M;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			int t = s[j] - '0';
			board[i][j] = t;
		}
	}
	int retv = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) { //의미가 없는 것은 제외
				int rv = 1e9;
				if (i > 0 && j > 0) {
					int a = board[i - 1][j];
					int b = board[i][j - 1];
					int c = board[i - 1][j - 1];
					rv = (rv < a) ? rv : a;
					rv = (rv < b) ? rv : b;
					rv = (rv < c) ? rv : c;
					rv++;
					board[i][j] = rv;
					retv = (retv < rv) ? rv : retv;
				}
			}
			retv = (retv < board[i][j]) ? board[i][j] : retv;
		}
	}
	long long ans = (retv * retv);
	cout << ans << "\n";
	return 0;
}
