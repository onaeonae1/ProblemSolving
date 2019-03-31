#include<iostream>
#define L 1005
using namespace std;
double tri[L][L] = { 0, }; //파스칼 삼각형 쓰기위함
double rainy[L] = { 0, }; //rainy[n] : n일 동안 계속 비가 올 확률
double sunny[L] = { 0, }; //sunny[n] = n일 동안 계속 해가 뜰 확률
double answers[L] = { 0, }; //값을 저장하는 배열
void initalize() //조합
{
	for (int i = 1; i <= 1000; i++)
	{
		tri[i][0] = 1.0;
		tri[i][1] = (double)i;
	}
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 2; j <= i + 1; j++)
		{
			tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
		}
	}
	rainy[0] = 1.0;
	rainy[1] = 0.75;
	sunny[0] = 1.0;
	sunny[1] = 0.25;
	for (int i = 2; i <= 1000; i++)
	{
		rainy[i] = rainy[i - 1] * (0.75);
		sunny[i] = sunny[i - 1] * (0.25);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	initalize(); //기본 설정해줌. 
	int c; //테스트 케이스
	scanf("%d", &c);
	int index = 0;
	while (c--)
	{
		index++;
		int n, m;
		scanf("%d %d", &n, &m); //높이, 기한 날짜

		if (n > 2 * m) //아무리 해도 도달 불가
		{
			answers[index] = 0.0;
		}
		if (n <= m) //뭔 짓을 해도 도달 가능
		{
			answers[index] = 1.0;
		}
		else
		{
			n = n - m; //비는 최소한 n-m 번은 내려야 한다. ->그보다 적게 내린다면 절대 m내에 n을 채울 수 없음.
			double temp = 0.0;
			for (int i = n; i <= m; i++)
			{
				temp += rainy[i] * sunny[m - i] * tri[m][i];
			}
			answers[index] = temp;
		}
	}
	for (int i = 1; i <= index; i++)
	{
		printf("%0.10f", answers[i]);
		printf("\n");
	}
	return 0;
}
