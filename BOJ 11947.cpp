#include<stdio.h>
unsigned long long int lovely;
int n, m;
int main()
{
	scanf("%d", &m);
	for (long long int j = 1; j <= m; j++) //테스트 케이스마다
	{
		lovely = 0;
		scanf("%d", &n);
		unsigned long long int tencount = 10;
		while (n >=tencount) //tencount 구해주는 과정
		{
			tencount = tencount * 10;
		}
		unsigned long long int middle = tencount / 2;
		if (n <= middle) //중간 값보다 작다. -> 넓이가 증가하는 방향이므로 그냥 본인 값 나오면 됨.
		{
			lovely = n * ((tencount - 1) - n);
		}
		else //중간 값보다 크다. -> 넓이가 감소하는 방향이므로 중간 값에 의존해야 함.
		{
			lovely = middle * ((tencount - 1) - middle);
		}
		printf("%llu\n",lovely);
	}
	return 0;
}
