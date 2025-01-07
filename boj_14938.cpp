#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int, int>> adj[105]; //adj[from] = {cost, to};
int points[105];
int V, E, L; // 정점, 간선, 이동 한계
int dist[105];
int INF = 1e9;
int dij2(int start) {
	int ret = 0;
	fill_n(dist, 104, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobq;
	jobq.push({ 0, start });
	dist[start] = 0;
	while (!jobq.empty()) {
		pair<int, int> now = jobq.top();
		jobq.pop();
		int currentNode = now.second;
		int currentCost = now.first;
		if (currentCost > L || currentCost > dist[currentNode]) {
			// 더 봐야 의미 없음
			continue; 
		}
		for (int i = 0; i < adj[currentNode].size(); i++) {
			pair<int, int> next = adj[currentNode][i];
			int nextNode = next.second;
			int nextCost = currentCost + next.first;
			if (nextCost <= L && nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				jobq.push({ nextCost, nextNode });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] <= L) {
			ret += points[i];
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> V >> L >> E;
	for (int i = 1; i <= V; i++) {
		cin >> points[i];
	}
	for (int i = 0; i < E; i++) {
		int from;
		int to;
		int cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to }); 
		adj[to].push_back({ cost, from });
	}

	// 끝점을 정할 필요 없음
	int ans = 0;
	for (int i = 1; i <= V; i++) {
		int t1 = dij2(i);
		ans = max(ans, t1);
	}
	cout << ans << "\n";
	return 0;
}
