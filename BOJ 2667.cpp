#include<stdio.h>
#include<algorithm>
#define SIZE 30
using namespace std;
bool compare(int a, int b)
{
	return a < b;
}
int n;
int localcount, totalcount[9999]; //단지에 해당하는 아파트 수
int variation; //단지 종류
int map[SIZE][SIZE]; //map
int visit[SIZE][SIZE];
void engine(int y, int x)
{
	localcount++;
	visit[y][x] = 1; //방문했음을 표시
	//4방향 탐색 과정
	if (map[y][x + 1] == 1 && visit[y][x+1]==0) //값이 있고, 방문한 적이 없음.
	{
		engine(y, x + 1);
	}
	if (map[y][x - 1] == 1 && visit[y][x-1]==0)
	{
		engine(y, x - 1);
	}
	if (map[y + 1][x] == 1 && visit[y + 1][x] == 0)
	{
		engine(y + 1, x);
	}
	if (map[y - 1][x] == 1 && visit[y - 1][x] == 0)
	{
		engine(y - 1, x);
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char temp[SIZE];
		scanf("%s", temp);
		for (int j = 0; j <= n-1; j++)
		{
			map[i][j+1] = temp[j] - '0';
		}
		getchar();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 1 && visit[i][j]==0)
			{
				variation++;
				visit[i][j] = 1;
				engine(i, j);
				totalcount[variation] = localcount;
			}
			localcount = 0;
		}
	}
	printf("%d\n", variation);
	sort(totalcount + 1, totalcount + variation + 1, compare);
	for (int i = 1; i <=variation; i++)
	{
		printf("%d\n", totalcount[i]);
	}
	return 0;
}
