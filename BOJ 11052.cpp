#include<stdio.h>
#define SIZE 1005
int A[SIZE];
int max[SIZE];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &A[i]);
		max[i] = A[i];
		//n개의 카드를 구매할때 최고로 드는 비용은 일단 이렇게 둔다.
	}
	for (int i = 2; i <= n; i++)
	{
		int a = 1;
		int b = i - 1;
		int alpha = max[a] + max[b];
		int beta = max[i];
		while (1)
		{
			if (a > b || (a+b)!=i) //앞에서 시작한 값과 뒤에서 시작한 값이 교차될 때
			{
				break;
			}
			else //교차 X 아직은 계산이 가능하다.
			{
				alpha = max[a] + max[b];
				beta = max[i];
				if (alpha > beta)
				{
					max[i] = alpha;
				}
				a++;
				b--;
			}
		}
	}
	printf("%d", max[n]);
	return 0;
}
