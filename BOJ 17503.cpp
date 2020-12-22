#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, k; //큐의 크기, 만족할 선호도, 전체 맥주의 수
vector<pair<int, int>> beers;
priority_queue<int> pq;
int search() {
	int sum = 0;
	for (int i = 0; i < k; i++) {
		pq.push(-beers.at(i).second); //만족도순으로 사용
		sum = sum + beers.at(i).second;
		if (pq.size() > n) { //초과
			sum = sum + pq.top(); //음수
			pq.pop();
		}
		if (pq.size() == n) {
			if (sum >= m) { //조건만족
				return beers.at(i).first;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int v, c; // 만족도, 도수
		scanf("%d %d", &v, &c);
		beers.push_back(make_pair(c, v)); //도수, 만족도순으로
	}
	//도수 순으로 정렬
	sort(beers.begin(), beers.end());
	int ans = search();
	printf("%d", ans);
	return 0;
}
