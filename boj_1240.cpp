#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N_MAX = 1005;
vector<pair<int, int>> tree[N_MAX + 1];
vector<int> dist(N_MAX + 1, -1);
int n, m;
void dfs(int node, int parent, int current) {
    dist[node] = current;
    for(int i =0; i<tree[node].size(); i++){
        pair<int, int> edge = tree[node][i];
        int nextNode = edge.first;
        int cost = edge.second;   
        if(nextNode!=parent){
            int next = current + cost;
            dfs(nextNode, node, next);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        tree[u].push_back({v, cost});
        tree[v].push_back({u, cost});
    }

    vector<pair<int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    for(int i=0; i<m; i++){
        pair<int, int> query = queries[i];
        fill(dist.begin(), dist.end(), -1); // 거리 배열 초기화
        dfs(query.first, -1, 0);
        cout << dist[query.second] << "\n";
    }

    return 0;
}
