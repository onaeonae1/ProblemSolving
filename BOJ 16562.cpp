#include<stdio.h>
#define lim 100005
#define INF 10000005
int getParent(int parent[], int x) //루트 노드 찾는 재귀함수
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = getParent(parent, parent[x]); 
	}
}
void unionParent(int parent[], int a, int b) //노드끼리 합쳐주고 가장 최소의 가격을 가져옴.
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)
	{
		parent[b] = a;
	}
	else if(a>=b)
	{
		parent[a] = b;
	}
}
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int N, M, K;; //사람수, 관계의 수, 소지금
	int parents[lim] = { 0, };  //연결 관계 표시를 위함
	int costs[lim] = { 0, };
	int check[lim] = { 0, };
	int sum = 0;
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 1; i <= N; i++) //사람의 수 만큼
	{
		parents[i] = i; //각자의 루트노드는 각자로 초기화 해줌.
		scanf("%d", &costs[i]); //비용을 입력받고
		check[i] = INF;
	}
	for (int i = 1; i <= M; i++) //서로의 관계 설정
	{
		int u, v;
		scanf("%d %d", &u, &v);
		unionParent(parents, u, v); //서로를 합침.
		unionParent(parents, v, u);
	}

	for (int i = 1; i <= N; i++) //해당 루트 내에서의 최솟값 탐색 과정
	{
		if (check[getParent(parents,i)] >= costs[i])
		{
			check[getParent(parents,i)] = costs[i];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (check[i] != INF)  //한번이라도 이 값이 바뀌었다면
		{
			sum += check[i]; 
		}
	}
	if (sum > K) //친구비 총합이 내 돈보다 많을 때
	{
		printf("Oh no");
	}
	else
	{
		printf("%d", sum);
	}
	return 0;
}
