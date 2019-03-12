#include<iostream>
#include<vector>
#include<algorithm>
#define L 100005
using namespace std;
int n, m; //정점수 , 간선 수
int parent[L];
int setSize[L];
struct edge
{
	int v1;
	int v2;
	int weight;
	bool operator<(edge &E) //정렬에 쓸거임
	{
		return weight < E.weight;
	}
};
vector<edge> E; //간선 정보를 담을 벡터 선언하기
int find_(int n) 
{
	if (n == parent[n]) 
	{
		return n;
	}
	return parent[n] = find_(parent[n]);
}
void union_(int a, int b) 
{
	a = find_(a);
	b = find_(b);
	if (a != b) 
	{
		// 크기가 작은 쪽이 큰 쪽으로 합치게끔 구현한다.
		if (setSize[a] < setSize[b]) 
		{
			swap(a, b);
		}
		parent[b] = a;
		setSize[a] += setSize[b];
		setSize[b] = 0;
	}
}
int main()
{
	cin >> n>>m;
	for (int i = 0; i < m; i++)
	{
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight;
		E.push_back({ v1, v2, weight });
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		setSize[i] = 0;
	}
	long long int sum = 0;
	for (int i = 0; i < E.size(); i++)
	{
		//같은 집합이 아니라면
		if ((find_(E[i].v1) )!= (find_(E[i].v2)))
		{
			union_(E[i].v1, E[i].v2);
			sum = sum + (E[i].weight);
		}
	}
	cout << sum;
	return 0;
}
