#include<iostream>
#define MOD 10007
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int multiply=1;
	//4 이하는 자신 값 그대로가 최대
	//5 부터는 3이 많을 수록 곱 커짐 -> 3으로 최대한 채우고, 남은 값 그대로 활용
	while (n >=5) {
		multiply *= 3;
		multiply %= MOD;
		n -= 3;
	}
	printf("%d", (multiply * n) % MOD);
	return 0;
}
