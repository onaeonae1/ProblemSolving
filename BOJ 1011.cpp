#include<stdio.h>
#define SIZE 50000
int search(int value)
{
	if (value == 1)
	{
		return 1;
	}
	long long int N, C, L1, M, L2;
	N = 1;
	while (1)
	{
		C = N * (N + 1);
		L1 = 2 * N;
		if (value <= C)
		{
			return L1;
		}
		M = (N + 1) *(N + 1);
		L2 = (2 * N) + 1;
		if (value > C && value<=M)
		{
			return L2;
		}
		N++;
	}
	return 0;
}
int main()
{
	long long int result[SIZE] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int alpha, beta, scala;
		scanf("%d %d", &alpha, &beta);
		scala = beta - alpha; //중요한 것은 서로 거리의 차
		int count = 0;
		result[i] = (long long int)search(scala);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", result[i]);
	}
}
