#include<iostream>
#define C 120
using namespace std;
int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n,d,p; //마을 수, 일자, 교도소 번호
		cin >> n >> d >> p;
		int map[C][C] = { 0, }; //인접 행렬
		double pro[C][C] = { 0, }; //확률
		double dp[C][C] = { 0, }; //dp[a][b] : a일에 b에 도달할 확률
		for (int i = 0; i < n; i++)
		{
			int count = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j]; //입력받고
				
				if (map[i][j] == 1)
				{
					count++;
				}
			}
			if (count > 0)
			{
				for (int j = 0; j < n; j++)
				{
					pro[i][j] = ((double)map[i][j] / count);;
				}
			}
		}
		dp[0][p] = 1; //시작 일자에는 무조건 교도소에 있을 확률 100 %
		for (int day = 1; day <= d; day++)
		{
			double sum = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					sum += dp[day - 1][j] * pro[j][i];
				}
				dp[day][i] = sum;
				sum = 0;
			}
		}
		int wonder;
		cin >> wonder;
		for (int i = 1; i <= wonder; i++)
		{
			int temp;
			cin >> temp;
			printf("%.8f ", dp[d][temp]);
		}
		printf("\n");
	}
	return 0;
}
