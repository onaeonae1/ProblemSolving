//BOJ 4673 : Self Number
#include<stdio.h>
#include<math.h>
int sum = 0;
int check[15000];
void draw(int num, int divide)
{
	sum = sum + (num / divide);
	if (divide == 1) //더이상 나눌 자리가 없음.
	{
		check[sum] = 1;
		sum = 0;
		return;
	}
	else
	{
		draw(num%divide, divide / 10);
	}

}
int main()
{
	int i, j, k;
	int div;
	int n = 1;
	for (i = 1; i <= 10000; i++) //d(1) ~ d(10000)
	{
		if (i >= 10000)
		{
			n = 10000;
		}
		else if (i >= 1000)
		{
			n = 1000;
		}
		else if (i >= 100)
		{
			n = 100;
		}
		else if (i >= 10)
		{
			n = 10;
		}
		sum = i;
		draw(i, n);
	}
	for (i = 1; i <= 10000; i++)
	{
		if (check[i] == 0)
		{
			printf("%d \n", i);
		}
	}
	return 0;
}
