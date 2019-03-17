#include<iostream>
#include<queue>
#define L 100000
using namespace std;
bool check[L+5];
int N, M; //형 동생 위치
int bfs(int n , int m)
{
	int second = 0; //시간 체크하기
	queue<int> q;
	q.push(n);
	while (1)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			n = q.front();
			q.pop();
			if (n == m) //형이 동생 따라잡음
			{
				return second;
			}
			if (n > 0 && check[n - 1] == 0) //한칸 빼기
			{
				q.push(n - 1);
				check[n - 1] = 1;
			}
			if (n+1 < L && check[n + 1] == 0) //한칸 더하기
			{
				q.push(n + 1);
				check[n + 1] = 1;
			}
			if (2 * n <= L && check[2 * n] == 0)
			{
				q.push(n * 2);
				check[n * 2] = 1;
			}
		}
		second++;
	}
}
int main()
{
	cin >> N >> M;
	cout << bfs(N, M)<<endl;
	return 0;
}
