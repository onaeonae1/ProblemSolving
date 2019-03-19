#include<stdio.h>
#include<iostream>
#define SIZE 105
#define INF 9999999
int N;
int map[SIZE][SIZE] = { 0, }; //높이 정보
int visit[SIZE][SIZE] = { 0, };
void search(int y, int x, int value)
{
	visit[y][x] = 1; //방문 표시
	if (x+1<=N)
	{
		if (map[y][x + 1] >value && visit[y][x + 1] == 0)
		{
			search(y, x + 1, value);
		}
	}
	if (x-1>=1)
	{
		if (map[y][x - 1] >value && visit[y][x - 1] == 0)
		{
			search(y, x - 1, value);
		}
	}
	if (y+1<=N)
	{
		if (map[y + 1][x] >value && visit[y + 1][x] == 0)
		{
			search(y + 1, x, value);
		}
	}
	if (y-1>=1)
	{
		if (map[y - 1][x] >value && visit[y - 1][x] == 0) //크기 벗어나는지 검사
		{
			search(y - 1, x, value);
		}
	}
	return;
}
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
	scanf("%d", &N);
	int highest = -INF;
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]); //map 정보를 입력받음 
			highest = comp(map[i][j], highest);
		}
	}
	for (int i = 0; i <= highest; i++)
	{
		int variation = 0;
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				visit[j][k] = 0;
			}
		}
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (map[j][k] >i && visit[j][k] == 0)
				{
					variation++;
					visit[j][k] = 1;
					search(j, k,i);
				}
			}
		}
		result = comp(result, variation);
	}
	printf("%d", result);
	return 0;
}
