#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int V, E;
int dist[205][205];
int next_node[205][205]; // 최단 경로에서 첫 번째 방문 노드

void floyd_warshall() {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_node[i][j] = next_node[i][k]; 
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> V >> E;

    // 초기화
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = (i == j) ? 0 : INF; 
            next_node[i][j] = j; 
        }
    }

    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        dist[from][to] = cost;
        dist[to][from] = cost;
        next_node[from][to] = to;
        next_node[to][from] = from;
    }

    floyd_warshall();

    // 결과 출력
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j) {
                cout << "- ";
            }
            else {
                cout << next_node[i][j] << " "; // i -> j로 가는 최단 경로의 첫 방문 노드
            }
        }
        cout << "\n";
    }

    return 0;
}
