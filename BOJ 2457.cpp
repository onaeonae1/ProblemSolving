#include<stdio.h>
#include<algorithm>
#define LIM 100005
using namespace std;
struct board
{
	int start;
	int end;
}flower[LIM];
bool compare(const board &x, const board &y)
{
	return x.start < y.start;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int q, w, e, r;
		scanf("%d %d %d %d", &q, &w, &e, &r);
		flower[i].start = (100 * q) + w;
		flower[i].end = (100 * e) + r;
	}
	sort(flower, flower + N, compare);
	int day = 301; //시작일
	int i = -1, flag = 0, temp = 0, ans = 0;
	while (day <= 1130 && i<N)
	{
		flag = 0;
		i++;
		for (int j = 0; j < N; j++)
		{
			if (flower[j].start > day)
			{
				break;
			}
			if (temp < flower[j].end)
			{
				temp = flower[j].end;
				flag = 1;
				i = j;
			}
		}
		if (flag == 1)
		{
			day = temp;
			ans++;
		}
		else
		{
			printf("0");
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}
