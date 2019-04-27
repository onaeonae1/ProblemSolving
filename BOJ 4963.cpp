#include<stdio.h>
#define Limit 100001
#define SIZE 55
void Engine(int w, int h, int map[][SIZE], int visit[][SIZE], int x, int y)
{
	visit[y][x] = 1;
	if (x<w) //오른쪽
	{
		if (map[y][x + 1] == 1 && visit[y][x + 1] == 0)
		{
			Engine(w, h, map, visit, x + 1, y);
		}
		if (y < h) //오른쪽 위
		{
			if (map[y + 1][x + 1] == 1 && visit[y + 1][x + 1] == 0)
			{
				Engine(w, h, map, visit, x + 1, y + 1);
			}
		}
		if (y > 1) //오른쪽 아래
		{
			if (map[y - 1][x + 1] == 1 && visit[y - 1][x + 1] == 0)
			{
				Engine(w, h, map, visit, x + 1, y - 1);
			}
		}
	}
	if (x > 1) //왼쪽
	{
		if (map[y][x - 1] == 1 && visit[y][x - 1] == 0)
		{
			Engine(w, h, map, visit, x - 1, y);
		}
		if (y < h)
		{
			if (map[y + 1][x - 1] == 1 && visit[y + 1][x - 1] == 0)
			{
				Engine(w, h, map, visit, x - 1, y + 1);
			}
		}
		if (y > 1)
		{
			if (map[y - 1][x - 1] == 1 && visit[y - 1][x - 1] == 0)
			{
				Engine(w, h, map, visit, x - 1, y - 1);
			}
		}
	}
	if (y < h)
	{
		if (map[y + 1][x] == 1 && visit[y + 1][x] == 0)
		{
			Engine(w, h, map, visit, x, y + 1);
		}
	}
	if (y > 1)
	{
		if (map[y - 1][x] == 1 && visit[y - 1][x] == 0)
		{
			Engine(w, h, map, visit, x, y - 1);
		}
	}
	return;
}
int Makemap(int w, int h)
{
	int variation = 0;
	int map[SIZE][SIZE] = { 0, };
	int visit[SIZE][SIZE] = { 0, };
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (visit[i][j] == 0 && map[i][j]==1)
			{
				variation++;
				Engine(w, h, map, visit, j, i);
			}
		}
	}
	return variation;
}
int main()
{
	int wideth, height; //넓이, 높이
	int Result[Limit] = { 0, };
	int count = 0;
	while (1)
	{
		scanf("%d %d", &wideth, &height);
		if (wideth == 0 && height == 0) //종료 조건
		{
			break;
		}
		else
		{
			Result[count] = Makemap(wideth, height);
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", Result[i]);
	}
	return 0;
}
