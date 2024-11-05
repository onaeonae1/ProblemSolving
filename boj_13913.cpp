#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int X, Y;
bool visited[100005];
int mem[100005];
int ans;
bool checkRange(int p) {
	bool isValid = (p >= 0 && p < 100005) && (!visited[p]);
	return isValid;
}
void bfs() {
	queue<pair<int, int>> jobq;
	jobq.push({ X, 0 });
	while (!jobq.empty()) {
		pair<int, int> now = jobq.front();
		jobq.pop();
		int nowPos = now.first;
		int nowCost = now.second;
		if (nowPos == Y) {
			ans = nowCost;
			return;
		}
		int alpha = nowPos + 1;
		int beta = nowPos - 1;
		int gamma = nowPos * 2;
		if (checkRange(alpha)) {
			mem[alpha] = nowPos;
			visited[alpha] = true;
			jobq.push({ alpha, nowCost + 1 });
		}
		if (checkRange(beta)) {
			mem[beta] = nowPos;
			visited[beta] = true;
			jobq.push({ beta, nowCost + 1 });
		}
		if (checkRange(gamma)) {
			mem[gamma] = nowPos;
			visited[gamma] = true;
			jobq.push({ gamma, nowCost + 1 });
		}

	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> X >> Y;
	bfs();
	vector<int> ansPath;
	ansPath.push_back(Y);
	for (int i = 0; i < ans; i++) {
		ansPath.push_back(mem[Y]);
		Y = mem[Y];
	}
	cout << ans << "\n";
	reverse(ansPath.begin(), ansPath.end());
	for (int i : ansPath) {
		cout << i << " ";
	}
	return 0;
}
