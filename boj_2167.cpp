#include<iostream>
using namespace std;
int arr[1005][1005];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int sty, stx, edy, edx;
		cin >> sty >> stx >> edy >> edx;
		int sum = 0; 
		for (int i = sty; i <= edy; i++) {
			for (int j = stx; j <= edx; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
