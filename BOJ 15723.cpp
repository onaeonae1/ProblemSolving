#include<stdio.h>
#define MAX 98765
#define SIZE 30
int map[SIZE][SIZE];
int n, m;
void initalize()
{
	for (int i = 1; i <= 26; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = MAX;
			}
		}
	}
}
void Floyd()
{
	for (int k = 1; k <= 26; k++)
	{
		for (int i = 1; i <= 26; i++)
		{
			for (int j = 1; j <= 26; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}
int main()
{
	initalize();
	scanf("%d %d", &n);
    for (int i = 1; i <= n; i++) //전제
	{
		char line[20];
		scanf(" %[^\n]", line); //처음에 입력 버퍼 비우고 공백 포함하여 문자열 받기 
		int alpha = line[0]-'a' + 1;
		int beta = line[5] -'a' + 1;
		map[alpha][beta] = 1;
	}
	
    Floyd(); //경로 탐색
	scanf("%d", &m);
    for (int i = 1; i <= m; i++) //논의 대상
	{
		char line[20];
		scanf(" %[^\n]", line);
		int alpha = line[0] - 'a' + 1;
		int beta = line[5] - 'a' + 1;
		if (map[alpha][beta] != MAX)
		{
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
	}
	return 0;
}
