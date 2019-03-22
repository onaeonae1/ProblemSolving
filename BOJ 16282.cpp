#include<stdio.h>
#include<math.h>
#define SIZE 65
int main()
{
	long long int A[SIZE] = { 0, };
	long long int N;
	int count=0;
	scanf("%lld", &N);
	for (int i = 1; i <= SIZE; i++)
	{
		long long int value;
		value = (((i + 1) * (pow(2, (i + 1))-1)) + i);
		A[i] = value;
		if (N <= A[i])
		{
			count = i;
			printf("%d\n", count);
			break;
		}
	}
	return 0;
}
