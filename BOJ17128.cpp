#include<iostream>
#define L 200005
#define ll long long 
using namespace std;
int C[L];
int S[L];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, q;
	ll sum = 0;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) { //소 입력
		scanf("%d", &C[i]);
	}
	for (int i = 0; i < n; i++) { //부분 합 초기화
		S[i] = 1;
		for (int j = 0; j < 4; j++) { //연속해서 4개 곱해준 후 합 
			int idx = (i + j) % n;
			S[i] *= C[idx];
		}
		sum += S[i]; //전체 합
	}
	for (int i = 0; i < q; i++) {
		int cp; 
		scanf("%d", &cp); //변경할 위치(1~n)
		for (int j = 0; j < 4; j++) { //앞의 S변경
			if (--cp == -1) { //0~n-1
				cp = n - 1;
			}
			S[cp] = -S[cp];
			sum += (2 * S[cp]); //적용 
		}
		printf("%lld\n", sum);
	}
	return 0;
}
