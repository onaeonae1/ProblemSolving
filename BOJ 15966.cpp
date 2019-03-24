#include<stdio.h>
#define L 1000005
int comp(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int DP[L] = { 0, };
	int N;
	scanf("%d", &N);
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		int value;
		scanf("%d", &value);
		DP[value] = comp(DP[value], DP[value - 1] + 1);
		max = comp(max, DP[value]);
	}
	printf("%d", max);
	return 0;
}
