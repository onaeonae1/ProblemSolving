#include<stdio.h>
#define SIZE 30
int main()
{
	char A[SIZE][SIZE];
	int N, M;
	scanf("%d %d", &N, &M); //문자열 갯수와 문자열의 길이
	getchar();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%c", &A[i][j]);
		}
		getchar();
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = M; j >=1; j--)
		{
			printf("%c", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
