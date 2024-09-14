#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		B.push_back(t*-1);
	}

	int cmpK = K * 2;
	int ans = -1;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 1; i < N; i++) { // 오른쪽
		for (int j = 0; j < i; j++) { //왼쪽
			int w = A[i] - A[j];
			if (w != 0) {
				int h = (cmpK) / w;
				int existIdx = lower_bound(B.begin(), B.end(), h*-1) - B.begin();
				if (existIdx < M) {
					int existHeight = B[existIdx] * -1;
					int resultArea = existHeight * w;
					if (resultArea <= cmpK) {
						ans = (ans < resultArea) ? resultArea : ans;
					}
				}
			}
		}
	}
	if (ans == -1) {
		cout << ans << "\n";
		return 0;
	}
	cout << fixed;
	cout.precision(1);
	cout << (double)(ans) / (double)2 << "\n";
	return 0;
}
