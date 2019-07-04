#include<iostream>
using namespace std;
int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int results[55] = { 0, };
	int c;
	int index = 0;
	cin >> c;
	while (c--) {
		int N, M; //배열의 길이와 최대 값
		cin >> N >> M;
		int A[10005] = { 0, };
		int start[10005] = { 0, }; int end[10005] = { 0, };
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 2; i <= M; i++) {
			int first = start[i - 1] + 1;
			int idx = first;
			for (int j = first; j < N; j++) {
				if (A[j] == i - 1) {
					idx = j + 1;
				}
			}
			start[i] = idx;
		}
		end[M] = N - 1;
		for (int i = M - 1; i > 0; i--) {
			int first = end[i + 1] - 1;
			int idx = first;
			for (int j = first; j > 0; j--) {
				if (A[j] == i + 1) {
					idx = j - 1;
				}
			}
			end[i] = idx;
		}
		int ret = 0;
		for (int i = 0; i <= M; i++) {
			int value = end[i] - start[i] + 1;
			ret = max(ret, value);
		}
		results[index] = ret;
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << "#" << i+1 << " " << results[i] << endl;
	}
	return 0;
}
