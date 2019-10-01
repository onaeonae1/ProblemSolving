#include<iostream>
using namespace std;
int main() {
	int N, S, M; //곡의 수 , 시작 볼륨, 최대 볼륨
	int V[105] = { 0, };
	bool check[105][1005] = { false, }; //check[a][b] :a번 곡일때 b번 볼륨 가능
	scanf("%d %d %d", &N, &S, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &V[i]);
	}
	int res = -1;
	check[0][S] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (check[i][j] == true) { //현재 사용가능한 값일때
				if (j + V[i] <= M) {
					check[i+1][j + V[i]] = true;
				}
				if (j - V[i] >= 0) {
					check[i+1][j - V[i]] = true;
				}
			}
		}
	}
	int max = -1;
	for (int i = 0; i <= 1000; i++) {
		if (check[N][i] == true){
			if (i >= max) {
				max = i;
			}
		}
	}
	if (max != -1) {
		res = max;
	}
	printf("%d\n", res);
	return 0;
}
