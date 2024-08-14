#include<iostream>
using namespace std;
int main() {
	int L;
	int N;
	scanf("%d", &L);
	scanf("%d", &N);
	int leftEnd = 100005;
	int rightEnd = 0;
	int midGap = 0;
	int before = -1;
	int after = -1;
	for (int i = 0; i < N; i++) {
		int now;
		scanf("%d", &now);
		if (i == 0) {
			leftEnd = now;
		}
		if (i == N - 1) {
			rightEnd = now;
		}
		if (i >= 1) {
			int temp = now - before;
			if (temp > midGap) {
				midGap = temp;
			}
		}
		before = now;
	}
	int rightGap = L - rightEnd;
	int leftGap = leftEnd;
	int answer = L;
	for (int i = 0; i < L; i++) {
		if(i*2 >= midGap && i>=leftGap && i>=rightGap){
			if (i <= answer) {
				answer = i;
			}
		}
	}
	printf("%d", answer);
	return 0;
}
