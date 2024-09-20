#include<iostream>
using namespace std;
int A[105][105];
int N, M;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> M;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int t;
				cin >> t;
				A[i][j] += t;
			}
		}
	}
	for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++) { cout << A[i][j] << " "; } cout << "\n"; }
	return 0;
}
