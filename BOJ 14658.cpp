#include<stdio.h>
#define LIM 500001
int main()
{
	int N, M, L, T;//가로크기, 세로크기, 그물의 한변 길이, 별똥별의 수
	int X[LIM] = { 0, };
	int Y[LIM] = { 0, };
	int max = -999;
	scanf("%d %d %d %d", &N, &M, &L, &T);
	for (int i = 1; i <= T; i++) 
	{
		scanf("%d %d", &X[i], &Y[i]); //별똥별의 정보를 (x,y) 좌표로 받음.
	}
	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= T; j++) //모든 별똥별의 위치에 대해
		{
			int x = X[i];
			int y = Y[j];
			int count = 0;
			//교차하는 (x,y) 위치를 구해준다.
			for (int k = 1; k <= T; k++) //펼친 트램펄린과 그에 들어가는 게 있는지 확인하는 과정
			{
				if ((X[k] >= x && X[k] <= x + L) && (Y[k] >= y && Y[k] <= y + L))
				{
					count++;
				}
			}
			if (count >= max)
			{
				max = count;
			}
		}
	}
	int result = T - max;
	printf("%d", result);
	return 0;
}
