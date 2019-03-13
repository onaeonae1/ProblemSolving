#include<stdio.h>
#define L 50
int DP[L] = { 0, };
void initalize()
{
	for (int i = 1; i <= 45; i++) //(26)*(26+1)/2 - >351
	{
		DP[i] = ((i)*(i + 1)) / 2; //DP 테이블 만들어두기
	}
}
int search(int K)
{
	int possible = 0;
	for (int i1 = 45; i1 >= 1; i1--)
	{
		for (int i2 = i1; i2 >= 1; i2--)
		{
			for (int i3 = i2; i3 >= 1; i3--)
			{
				int sum = (DP[i1] + DP[i2]);
				sum += DP[i3];
				if (sum == K)
				{
					possible = 1;
					return possible;
				}
			}
		}
	}
	return possible;
}
int main()
{
	initalize();
	int answers[1005] = { 0, };
	int c;
	scanf("%d", &c);
	for (int i = 1; i <= c; i++)
	{
		int k; //표현 가능한지 궁금한 값.
		scanf("%d", &k);
		answers[i] = search(k);
	}
	for (int i = 1; i <= c; i++)
	{
		printf("%d\n", answers[i]);
	}
	return 0;
}
