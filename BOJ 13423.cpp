#include<iostream>
#include<algorithm>
#define L 1005
using namespace std;
int dots[L]; //점의 위치 정보, -1억~ 1억 사이 값이므로 int
int n, t; //점의 수, 테스트 케이스 수
int main()
{
	cin >> t;
	int answers[L] = { 0, };
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		int sum = 0; //각 테스트 케이스에서 가능한 three dots의 경우의 수
		for (int j = 1; j <= n; j++)
		{
			cin >> dots[j];
		}
		sort(dots + 1, dots + n + 1); //점들을 오름차순 정렬
		for (int j = 2; j <= n - 1; j++)
		{
			int a = 1; //앞
			int b = j; //중간
			int c = n; //끝
			int alpha = dots[b] - dots[a];
			int beta = dots[c] - dots[b];
			while (true)
			{
				if (a >= b || c <= b) //더이상 탐색 불가
				{
					break;
				}
				else //아직 탐색 가능함.
 				{
					if (alpha == beta) //같을 경우
					{
						sum++;//더해주고
						a++; 
						c--;
						//다음 연산을 위해 한칸 씩 이동해줌
					}
					else
					{
						if (alpha > beta) //앞의 차이가 더 크므로
						{
							a++; //a를 한칸 이동 -> alpha를 줄이기 위함
						}
						if (alpha < beta) //뒤의 차이가 더 크므로
						{
							c--; //c를 한칸 이동 - >beta를 줄이기 위함
						}
					}
				}
				alpha = dots[b] - dots[a];
				beta = dots[c] - dots[b];
			}
		}
		answers[i] = sum;
	}
	for (int i = 1; i <= t; i++)
	{
		cout << answers[i] << endl;
	}
	return 0;
}
