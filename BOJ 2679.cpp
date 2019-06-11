#include<stdio.h>
#define N 10005
double data[N];
int n;
double temp, max;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &data[i]);
	}
	max = data[1];
	temp = data[1];
	for (int i = 2; i <= n; i++)
	{
		if (data[i] > temp*data[i])
		{
			temp = data[i];
		}
		else
		{
			temp = temp * data[i];
		}

		if (temp > max)
		{
			max = temp;
		}
	}
	printf("%.3lf", max);
	return 0;
}
