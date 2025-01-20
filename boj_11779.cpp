#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E, S, T;
vector<pair<int, int>> adj[1005]; // adj[start] = {cost, to};
int dist[1005]; // dist[to] = cost of start~to
int parent[1005]; // parent[now] = real parent of..
int INF = 1e9;
void dij() {
	fill_n(dist, 1004, INF);
	fill_n(parent, 1004, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> jobq;
	jobq.push({ 0, S });
	dist[S] = 0;
	while (!jobq.empty()) {
		pair<int, int> now = jobq.top();
		jobq.pop();

		int currentCost = now.first;
		int currentNode = now.second;
		if (currentCost > dist[currentNode]) continue;
		for (auto next : adj[currentNode]) {
			int nextNode = next.second;
			int nextCost = next.first + currentCost;

			if (nextCost < dist[nextNode]) {
				dist[nextNode] = nextCost;
				parent[nextNode] = currentNode;
				jobq.push({ nextCost, nextNode });
			}
		}
	}
	cout << dist[T] << "\n";
	vector<int> ret;
	while (T != -1) {
		ret.push_back(T);
		T = parent[T];
	}
	cout << ret.size() << "\n";
	for (int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i] << (i == 0 ? "\n" : " ");
	}

}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> V;
	cin >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost, to });
	}
	cin >> S >> T;
	dij();
	return 0;
}
