#include<iostream>
using namespace std;
int A[11];
int cal(int start, int end) {
	int temp = 1;
	for (int i = start; i <= end; i++) {
		temp = temp * A[i];
	}
	return temp;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	int result = 0;
    //그룹의 시작위치를 정해줘서 완전탐색 돌리기 가능.
    //곱셈의 범위는 cal 함수를 불러다가 해결!
	for (int a = 1; a <= N - 3; a++) {
		int sum = 0;
		for (int b = a + 1; b <= N - 2; b++) {
			for (int c = b + 1; c <= N - 1; c++) {
				for (int d = c + 1; d <= N; d++) {
					sum = cal(a, b - 1) + cal(b, c - 1) + cal(c, d - 1) + cal(d, N);
					result = max(sum, result);
				}
			}
		}
	}
	cout << result << endl;
    return 0;
}
