#include<stdio.h>
#define SIZE 1005
int main()
{
	int D[SIZE] = { 0, };
	D[1] = 1;
	D[2] = 2;
	int n;
	scanf("%d", &n);
	if (n >= 3)
	{
		for (int i = 3; i <= n; i++)
		{
			int head = D[i - 1] % 10007;
			int tail = D[i - 2] % 10007;
			int value = (head + tail) % 10007;
			D[i] = value;
		}
		printf("%d\n", D[n]);
	}
	else
	{
		printf("%d\n", D[n]);
	}
	return 0;
}
