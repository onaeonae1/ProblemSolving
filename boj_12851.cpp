#include<iostream>
#include<queue>
#include<map>
using namespace std;
int N, K;
bool visited[100005];
bool adhoc = true;
int retCost = 1e9;
int retCnt = 0;
bool checkInRange(int p) {
	bool validRange = (0 <= p) && (p <= 100005) && (!visited[p]);
	return validRange;
}
void bfs() {
	queue<pair<int, int>> jobq;
	jobq.push({ N, 0 });
	visited[N] = true;
	while (!jobq.empty()) {
		pair<int, int> now = jobq.front();
		int pos = now.first;
		int cost = now.second;
		jobq.pop();
		visited[pos] = true;
		if (pos == K) {
			if (adhoc) {
				retCost = cost;
				adhoc = false;
				retCnt++;

			}
			else if(cost==retCost){
				retCnt++;
			}
		}
		int alpha = pos * 2;
		int beta = pos + 1;
		int gamma = pos - 1;
		if (checkInRange(alpha)) {
			jobq.push({ alpha, cost + 1 });
		}
		if (checkInRange(beta)) {
			jobq.push({ beta, cost + 1 });
		}
		if (checkInRange(gamma)) {
			jobq.push({ gamma, cost + 1 });
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> K;
	bfs();
	cout << retCost << "\n"; 
	cout << retCnt << "\n";
	return 0;
}
