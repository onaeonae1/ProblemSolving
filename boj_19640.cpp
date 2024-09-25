#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct empl {
	int idx, line, zzam, hurry;
};
struct cmp {
	bool operator()(empl a, empl b) {
		if (a.zzam == b.zzam) {
			if (a.hurry == b.hurry)
				return a.line > b.line;
			return a.hurry < b.hurry;
		}
		return a.zzam < b.zzam;
	}
};
int N, K, M, zzam, hurry;
queue<empl> eachline[100000];
int cnt = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K; 
	for (int i = 0; i < N; i++) {
		cin >> zzam >> hurry;

		eachline[i % M].push({ i, i % M, zzam, hurry });
	}
	priority_queue<empl, vector<empl>, cmp> pq;
	for (int i = 0; i < M; i++) {
		if (!eachline[i].empty()) {
			pq.push(eachline[i].front());
			eachline[i].pop();
		}
	}
	while (cnt < N) {
		empl next = pq.top();
		pq.pop();
		if (next.idx == K)
			break;
		else {
			if (!eachline[next.line].empty()) {
				pq.push(eachline[next.line].front()); 
				eachline[next.line].pop();
			}
		}
		cnt++;
	}
	cout << cnt <<"\n"; 
	return 0;
}
