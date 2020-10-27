#include<iostream>
#include<cstring>
#define L 305
typedef long long ll;
using namespace std;
ll DP[L][L]; // DP[i][j] : 공 i개, 높이 1~j까지 트리의 경우의 수 합
ll MOD = 100030001;
int b, h;
ll func(int n, int h) {
	if (n == 0) { //공이 더 없다. ->반대쪽 트리가 완성되면 문제없다
		return 1;
	}
	else if (h == 0) { //사용할 공은 남는데 더 확장불가 -> 터짐
		return 0;
	}
	ll& now = DP[n][h];
	if (now != -1) { //값 있나 체크
		return now;
	}
	else {
		now= 0; //0으로 초기화
	}
	for (int i = 0; i < n; i++) {
		ll leftTree = func(i, h - 1);
		ll rightTree = func(n - 1 - i, h - 1);
		now += leftTree * rightTree;
		now %= MOD;
	}
	return now;
}
int main() {
	scanf("%d %d", &b, &h); //공의 갯수
	memset(DP, -1, sizeof(DP));
	//func(b,h) - func(b,h-1) : 겹치는 부분 제거. 정확하게 높이 h로 만들어지는 경우 찾기 위함
	printf("%lld\n", (func(b, h)+MOD - func(b,h-1)+MOD)%MOD);
	return 0;
}
