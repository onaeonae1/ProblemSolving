#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 100005
bool compare(int a, int b)
{
	return a < b;
}
int main()
{
	int N;
	int A[SIZE] = { 0, };
	int B[SIZE] = { 0, };
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A + 1, A + N + 1, compare); //정렬을 해주고
	int value = 1;
	long long int sum = 0;
	B[1] = 1; //1이 최소한 하나는 있어야 함
	for (int i = 2; i <= N; i++)
	{
		if (A[i] > value)
		{
			value++;
			B[i] = value;
		}
		else
		{
			B[i] = A[i];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		sum = sum + (A[i] - B[i]);
	}
	printf("%lld", sum);
	return 0;
}
