#include<stdio.h>
#include<algorithm>
#define L 1000005
#define INF 1000000005
using namespace std;
bool compare(int a, int b)
{
	return a <= b;
}
int main()
{
	int N, point;
	int A[L] = { 0, };
	scanf("%d %d", &N, &point);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]); //유닛들의 현재 레벨을 입력받음.
	}
	sort(A + 1, A + N + 1, compare); //정렬해주고
	int level = 1;
	A[N + 1] = INF;
	while (point > 0)
	{
		if (A[level] < A[level+1])
		{
			int nextvalue = point - level;
			if (nextvalue < 0)
			{
				break;
			}
			else
			{
				for (int j = 1; j <= level; j++)
				{
					A[j]++;
					point--;
				}
			}
		}
		else
		{
			level++;
		}
	}
	printf("%d", A[1]);
	return 0;
}
