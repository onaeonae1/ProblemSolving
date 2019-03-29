#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 510
int A[N]; //데이터의 값을 저장.
int dy[N]; //LIS값을 찾는 용도
struct abc
{
	int start;
	int end;
}DATA[N];
bool compare(const abc &a, const abc &b)
{
	return a.start < b.start;
}
int main()
{
	int i, j, k;
	int n;
	scanf("%d", &n);
	int max = -5000;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &DATA[i].start, &DATA[i].end);
	}
	sort(DATA + 1, DATA + n + 1, compare);
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (DATA[i].end > DATA[j].end && dy[i] < dy[j] + 1)
			{
				dy[i] = dy[j] + 1;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (dy[i] >= max)
		{
			max = dy[i];
		}
	}
	int ans = n - max;
	printf("%d", ans);
	return 0;
}
