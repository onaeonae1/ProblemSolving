#include<iostream>
#define C 55
#define N 105
using namespace std;
int comp(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int c;
	cin >> c; //테스트 케이스 입력받고
	int result[C]; //케이스당 결과값
	for (int i = 1; i <= c; i++)
	{
		int max = -1;
		int triangle[N][N] = { 0, }; //삼각형 자연수들
		int table[N][N] = { 0 , }; //최고값 저장용 테이블
		int n;
		cin >> n;
		//삼각형 자연수들 입력받기
		for (int j = 1; j <= n; j++) //y
		{
			for (int k = 1; k <= j; k++) //x
			{
				cin >> triangle[j][k];
			}
		}
		//탐색 과정
		table[1][1] = triangle[1][1];
		max = comp(max, table[1][1]);
		for (int j = 1; j <= n - 1; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				int nowvalue = table[j][k]; //현재 내가 보고 있는 테이블의 값
				//바로 아래 값 갱신
				table[j + 1][k] = comp(table[j + 1][k], triangle[j + 1][k] + nowvalue);
				max = comp(max, table[j + 1][k]);
				//오른쪽 대각선 아래 값 갱신
				table[j + 1][k + 1] = comp(table[j + 1][k + 1], triangle[j + 1][k + 1] + nowvalue);
				max = comp(max, table[j + 1][k + 1]);
			}
		}
		result[i] = max;
	}
	for (int i = 1; i <= c; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}
