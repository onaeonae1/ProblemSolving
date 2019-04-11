#include<stdio.h>
#define SIZE 100000
#define swap(a,b){int t= a; a= b; b=t;} //두 변수를 바꿔주는 수식
int find(int u, int parent[SIZE])
{
	if (u == parent[u]) //본인이 루트 노드이면
	{
		return u;
	}
	return parent[u] = find(parent[u],parent); //루트 찾으러 떠난다.
}
void merge(int u, int v, int level[SIZE], int parent[SIZE]) //u노드가 있는 트리에 v 노드가 있는 트리를 병합하는 것.
{
	u = find(u,parent);
	v = find(v,parent); //각자의 루트를 찾고
	if (u == v) //서로 루트가 같다면 이미 병합된 상태임
	{
		return;
	}
	if (level[u] > level[v]) //u가 더 위에 있어야 하니깐
	{
		swap(u, v);
	}
	parent[u] = v; //합쳐주는 과정
	if (level[u] == level[v])
	{
		++level[v];
	}
}
int main()
{
	int n, m;
	int parent[SIZE] = { 0, }; //트리의 루트 노드
	int level[SIZE] = { 0, }; //트리의 노드의 현재 레벨. 만약 루트 노드라면 레벨이 1일 것이다. 
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int val;
			scanf("%d", &val);
			if (j > i && val == 1) //n*n 행렬에서 대각선 오른쪽 값들이 여결되어 있을 때
 			{
				merge(i, j,level,parent);
			}
			
		}
	}
	int checker = 1;
	int val;
	scanf("%d", &val);
	int u = find(val,parent);
	for(int i = 0; i <= m-1; i++) //여행할 경로
	{
		scanf("%d", &val);
		if (u != find(val,parent))
		{
			checker = 0;
			break;
		}
	}
	if (checker == 0)
	{
		printf("NO");
	}
	else
	{
		printf("YES");
	}
	return 0;
}
