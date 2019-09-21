#include<iostream>
#include<vector>
#define L 200000
using namespace std;
int N, Q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> S(N);
	for (int i = 0; i < N; i++) { //소 입력받고
		cin >> A[i];
	}
	long long int sum =0 ;
	for (int i = 0; i < N; i++) { //S 초기화
		S[i] = A[i%N] * A[(i + 1) % N] * A[(i + 2) % N] * A[(i + 3) % N];
		sum += S[i];
	}
	for (int i = 0; i < Q; i++) { //욱가가 질문을 하나씩 던진다
		int idx;
		cin >> idx;
		if (--idx == -1) {
			idx = N - 1;
		}
		for (int j = 0; j < 4; j++) {
			S[idx] = -S[idx];
			sum += 2 * S[idx];
			if (--idx == -1) {
				idx = N - 1;
			}
		}
		cout << sum << '\n';
	}
	return 0; 
}
