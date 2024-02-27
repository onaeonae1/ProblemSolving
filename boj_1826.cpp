#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, L, P;
vector<pair<int, int>> stations; // pos, fuelValue
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int pos, fuelValue;
		scanf("%d %d", &pos, &fuelValue);
		stations.push_back(make_pair(pos, fuelValue));
	}
	scanf("%d %d", &L, &P);
	sort(stations.begin(), stations.end());


	priority_queue<int> pq;
	int cnt = 0;
	int idx = 0;
	bool isPossible = true;
	while (P < L) {
		// 일단 안되는 친구들은 다 담는다
		while (idx < N && P >= stations.at(idx).first) {
			pq.push(stations.at(idx++).second);
		}
		if (pq.empty()) {
			isPossible = false;
			break;
		}

		// 연료 채운다
		P += pq.top();
		pq.pop();
		cnt++;
	}

	cnt = (isPossible) ? cnt : -1;
	printf("%d", cnt);
	return 0;
}
