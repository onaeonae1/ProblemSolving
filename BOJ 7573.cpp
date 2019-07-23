#include <stdio.h>
#define N 101
int X[N], Y[N];
int qwer, L, n, x, y, nx, ny, count = 0, MAX = 0;
int main()
{
	/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	*/
	scanf("%d%d%d", &qwer, &L, &n);
	for (int i = 1; i <= n; i++) //물고기의 위치 입력받음 .
	{
		scanf("%d%d", &X[i], &Y[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			x = X[i];
			y = Y[j];
			//그물의 종류
			for (nx = (L / 2) - 1, ny = 1; nx >= 1; nx--, ny++) 
			{
				count = 0;
				for (int k = 1; k <= n; k++) 
				{
					if (X[k] >= x && X[k] <= x + nx &&	Y[k] >= y && Y[k] <= y + ny) 
					{
						count++;
					}
				}
				if (MAX < count)
				{
					MAX = count;
				}
			}
		}
	}
	printf("%d", MAX);
	return 0;
}
