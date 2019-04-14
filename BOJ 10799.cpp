//https://www.acmicpc.net/problem/10799
//BOJ 쇠막대기
#include<stdio.h>
#include<string.h>
#define L 100005
char map[L];
int count, stack, sum;
int main()
{
	scanf("%s", map);
	for (int i = 1; i < strlen(map); i++)
	{
		if (map[i] == '(')
		{
			count++;
			if (map[i - 1] == '(')
			{
				stack++;
			}
		}
		else if (map[i] == ')')
		{
			count--;
			if (map[i - 1] == '(')
			{
				sum = sum + (stack + count + 1);
				stack = 0;
			}
		}
	}
	printf("%d \n", sum);
	return 0;
}
