#include<iostream>
#define L 200005
using namespace std;
int main() {
	int a[L] = { 0, };
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	int gap = N - V + 1;
	//질문 들어오는 대로 처리
	for (int i = 1; i <= M; i++) {
		int num; 
		scanf("%d", &num);
		if (num < N) { //그대로 찍으면 된다.
			printf("%d\n", a[num+1]);
		}
		else { //계산좀 해줘야함
			int target = (num - N) % gap + V;
			printf("%d\n", a[target]);
		}
	}
	return 0;
}
