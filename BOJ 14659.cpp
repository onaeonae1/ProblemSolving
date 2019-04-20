#include<stdio.h>
#define INF 30000
int main()
{
	int A[INF + 5] = { 0, };
	int DP[INF + 5] = { 0, };
	int n;
	int max = -INF;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = i+1; j <= n; j++)
		{
			if (A[i] < A[j])
			{
				break;
			}
			else
			{
				count++;
			}
		}
		if (count > max)
		{
			max = count;
		}
	}
	printf("%d", max);
	return 0;
}
