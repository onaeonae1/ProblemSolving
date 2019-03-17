#include<stdio.h>
int main()
{
	long long int N;
	long long int sum = 0;
	scanf("%lld", &N);
	long long int K = 2; 
	N *= 2;
	while (N >= K)
	{
		sum += K * ((N / K - N / (K * 2)));
		K *= 2;
	}
	printf("%lld", sum);
	return 0;
}
