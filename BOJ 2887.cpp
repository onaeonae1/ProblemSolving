#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define L 100005
using namespace std;
//구조체 정의
struct Planet {
	int idx;
	int x;
	int y;
	int z;
};
struct Path {
	int idx1;
	int idx2;
	int value;
};
int parent[L];
Planet planets[L];
vector<Path> paths;
int N;
//비교 함수들
bool cmpX(const Planet &a, const Planet &b) {
	return a.x < b.x;
}
bool cmpY(const Planet &a, const Planet &b) {
	return a.y < b.y;
}
bool cmpZ(const Planet &a, const Planet &b) {
	return a.z < b.z;
}
bool cmpV(const Path &a, const Path &b) {
	return a.value < b.value; 
}
int find(int idx) {
	if (parent[idx] == idx) {
		return idx;
	}
	else {
		return parent[idx] = find(parent[idx]);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		planets[i].idx = i;
		parent[i] = i;
		scanf("%d %d %d", &planets[i].x, &planets[i].y, &planets[i].z);
	}
	//x기준
	sort(planets + 0, planets + N, cmpX);
	for (int i = 0; i < N - 1; i++) {
		Path P;
		P.idx1 = planets[i].idx;
		P.idx2 = planets[i + 1].idx;
		P.value = abs(planets[i].x - planets[i+1].x);
		paths.push_back(P);
	}
	//y기준
	sort(planets + 0, planets + N, cmpY);
	for (int i = 0; i < N - 1; i++) {
		Path P;
		P.idx1 = planets[i].idx;
		P.idx2 = planets[i + 1].idx;
		P.value = abs(planets[i].y - planets[i + 1].y);
		paths.push_back(P);
	}
	//z기준
	sort(planets + 0, planets + N, cmpZ);
	for (int i = 0; i < N - 1; i++) {
		Path P;
		P.idx1 = planets[i].idx;
		P.idx2 = planets[i + 1].idx;
		P.value = abs(planets[i].z - planets[i + 1].z);
		paths.push_back(P);
	}
	//가중치에 따라 정렬
	sort(paths.begin(), paths.end(), cmpV);
	//크루스칼 돌리기
	int result = 0;
	for (int i = 0; i < paths.size(); i++) {
		int p1 = find(paths.at(i).idx1);
		int p2 = find(paths.at(i).idx2);
		if (p1 != p2) { //같은 집합에 없다 합쳐야 함
			parent[p2] = p1;
			result += paths.at(i).value;
		}
	}
	printf("%d", result);
	return 0;
}
