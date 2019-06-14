#include<stdio.h>
#include<algorithm>
#define SIZE 100005
using namespace std;
bool compare(int a, int b)
{
	return a >= b;
}
int main()
{
	int N;
	int A[SIZE] = { 0, };
	int max = -99999;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A + 1, A + N + 1, compare); //정렬 해주고
	for (int i = 1; i <= N; i++)
	{
		int nextvalue = A[i] * i;
		if (nextvalue >= max)
		{
			max = nextvalue;
		}
	}
	printf("%d\n", max);
	return 0;
}
