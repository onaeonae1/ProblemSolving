#include <stdio.h>
#define N 500+5 
int n;
int data[N][N]; //실제 값을 입력받음.
int point[N][N]; //DFS 결과를 저장.
int cmp(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int dfs(int x, int y) {
	if (point[x][y] != 0)
	{
		return point[x][y];
	}
	point[x][y] = 1;
	//비교하는 부분 사방의 값들을 내 자리의 포인트값(이동가능 하 최대 자리)과 비교하고 더 크면 그 값을 가짐.
	if (data[x][y] < data[x][y + 1])
	{
		point[x][y] = cmp(point[x][y], dfs(x, y+1) + 1);
	}
	if (data[x][y] < data[x][y - 1])
	{
		point[x][y] = cmp(point[x][y], dfs(x, y-1) + 1);
	}
	if (data[x][y] < data[x + 1][y])
	{
		point[x][y] = cmp(point[x][y], dfs(x+1,y) + 1);
	}
	if (data[x][y] < data[x - 1][y])
	{
		point[x][y] = cmp(point[x][y], dfs(x-1, y) + 1);
	}
	return point[x][y];
}

int main()
{
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &data[i][j]);
		}
	}
	int total_max = 0;
	for (i = 1; i <= n; i++) 
	{
		for (j = 1; j <= n; j++)
		{
			total_max = cmp(total_max, dfs(i, j));
		}
	}
	printf("%d\n", total_max);
	return 0;
}
