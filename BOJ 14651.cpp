#include<iostream>
#define mod 1000000009
long long int three[33335] = { 0, };
using namespace std;
int main() {
	int n;
	three[1] = 0;
	three[2] = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		three[i] = (three[i - 1] * 3) % mod;
	}
	printf("%lld\n", three[n]);
	return 0;
}
