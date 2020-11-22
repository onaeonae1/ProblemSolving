#include<iostream>
#include<vector>
#include<algorithm>
#define L 1005
#define ll long long 
using namespace std;
int n;
int parent[L];
int setSize[L];
struct edge{
	int v1, v2, weight;
	bool operator<(edge &alpha) {//정렬에 사용
		return weight < alpha.weight;
	}
};
vector<edge> E; //간선 정보를 담을 벡터 선언하기
int search(int n){ //union-find 에서 find
	if (n == parent[n]){
		return n;
	}
	return parent[n] = search(parent[n]);
}
void merge(int a, int b){ //union-find 에서 union
	a = search(a);
	b = search(b);
	if (a != b) {
		// 크기가 큰 집합쪽으로 병합
		if (setSize[a] < setSize[b]){
			swap(a, b);
		}
		parent[b] = a;
		setSize[a] += setSize[b];
		setSize[b] = 0;
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int temp;
			scanf("%d", &temp);
			if (j > i) {//필요한 간선들만 
				E.push_back({ i,j,temp }); //edge 벡터에 넣어줌
			}
		}
	}
	sort(E.begin(), E.end()); //간선 정렬
	for (int i = 0; i < n; i++){
		parent[i] = i;
		setSize[i] = 1;
	}
	ll sum = 0;
	int connected = 0;
	//크루스칼 돌리기
	for (int i = 0; i < E.size(); i++){
		if (connected == n - 1) {//이미 MST 구성완료
			break;
		}
		else if ((search(E[i].v1)) != (search(E[i].v2))){ 
			//같은 집합이 아니라면 == 트리구성에 문제 없다
			merge(E[i].v1, E[i].v2);
			sum = sum + (E[i].weight);
			connected++;
		}
	}
	cout << sum;
	return 0;
}
