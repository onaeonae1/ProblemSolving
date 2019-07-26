include<stdio.h>
#define N 10001
int DP[N];
int A[N];
int max(int alpha, int beta, int gamma)
{
	if (alpha >= beta)
	{
		if (alpha > gamma)
		{
			return alpha;
		}
		else
		{
			return gamma;
		}
	}
	else //alpha<beta
	{
		if (beta > gamma)
		{
			return beta;
		}
		else //beta<gamma
		{
			return gamma;
		}
	}
}
int main()
{
	int L; //포도주의 갯수
	scanf("%d", &L);
	for (int i = 1; i <= L; i++) //입력
	{
		scanf("%d", &A[i]);
	}
	DP[1] = A[1];
	DP[2] = A[1] + A[2];
	//초기 설정
	for (int i = 3; i <= L; i++) //동적 돌아가는 과정
	{
		int head = DP[i - 3]+A[i-1]+A[i];
		int tail = DP[i - 2] + A[i];
		DP[i] = max(head, tail, DP[i-1]);
		//계단 오르기와 다르게 무조건 올라갈 필요가 없으므로
		//DP[i-1] 또한 고려해준다.
	}
	int maximum = -50000;
	for (int i = 1; i <= L; i++)
	{
		if (DP[i] > maximum)
		{
			maximum = DP[i];
		}
	}
	printf("%d", maximum);
	return 0;
}
