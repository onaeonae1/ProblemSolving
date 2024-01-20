#include<iostream>
long long int sum = 1;
long long int N;
long long int divider = 120;
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < 5; i++) {
		sum *= (N - i);
	}
	sum = sum / divider;
	printf("%lld", sum);
	return 0;
}
