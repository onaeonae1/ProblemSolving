#include<iostream>
#include<vector>
#define N 15
#define INF 9999999
using namespace std;
int c;
int n;
double dist[N][N];
double min(double a, double b)
{
	if (a <= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
double shortest(vector<int>& path, vector<bool>& visited, double current)
{
	if (path.size() == n) //base case : 모든 도시 방문
	{
		return current;
	}
	double temp = INF;
	for (int i = 0; i < n; i++) //간선 확인
	{
		if (visited[i] == false) //방문 하지 않았을 때
		{
			int now = path.back(); 
			path.push_back(i);
			visited[i] = true;
			double route = shortest(path, visited, current + dist[now][i]);
			temp = min(temp, route);
			visited[i] = false;
			path.pop_back();
		}
	}
	return temp;
}
int main()
{
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		double answer = INF;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> dist[j][k];
			}
		}
		for (int j = 0; j < n; j++)
		{
			vector<bool> visited(n, false); //방문했는지
			vector<int> path(1, j); //경로 저장용
			visited[j] = true; //시작 도시 체크해주기

			double temp = shortest(path, visited, 0);
			if (answer > temp)
			{
				answer = temp;
			}
			//소수점 10자리 고정 목적
			cout << fixed;
			cout.precision(10);
		}
		cout << answer << endl;
	}
}
