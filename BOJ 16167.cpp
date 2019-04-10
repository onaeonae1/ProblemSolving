#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 200 + 5
#define INF 999999999
using namespace std;
int N, M;
vector<pair<int, int>>map[MAX]; //map 그자체
pair<int, int> table[MAX]; //거리, 방문 노드 갯수
void process()
{
	queue<int> q;
	q.push(1); //시작 노드 방문했으므로 +1
	//시작 지점
	table[1].first = 0; 
	table[1].second = 1; 
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < map[now].size(); i++)
		{
			int near = map[now][i].first; //간선이 연결된 노드
			int neardist = map[now][i].second; //간선의 거리
			if (table[near].first == (table[now].first + neardist))
			{
				if (table[near].second > table[now].second + 1)
				{
					table[near].second = table[now].second + 1;
					q.push(near);
				}
			}
			if (table[near].first > table[now].first + neardist)
			{
				table[near].first = table[now].first + neardist;
				table[near].second = table[now].second + 1;
				q.push(near);
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M); //노드, 간선 갯수
	for (int i = 0; i < M; i++) 
	{
		int a, b, c, d, e;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		if (e > 10) //10분이 넘어가서 추가요금 발생
		{
			c = (c + (e - 10)*d);
		}
		map[a].push_back({ b,c }); //	
	}
	for (int i = 0; i <= N; i++)
	{
		table[i].first = INF;
		table[i].second = INF;
	}
	process();
	if (table[N].first == INF)
	{
		printf("It is not a great way.");
	}
	else
	{
		printf("%d %d", table[N].first, table[N].second);
	}
	return 0;
}
