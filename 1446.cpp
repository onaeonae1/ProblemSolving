#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int INT_MAX = 99999999;
struct Edge {
    int start, end, length;
};

int main() {
    int N, D;
    cin >> N >> D;

    vector<Edge> shortcuts(N);
    for (int i = 0; i < N; ++i) {
        cin >> shortcuts[i].start >> shortcuts[i].end >> shortcuts[i].length;
    }

    vector<int> dist(D + 1, INT_MAX);
    dist[0] = 0;

    for (int i = 0; i <= D; ++i) {
        if (i > 0) {
            dist[i] = min(dist[i], dist[i - 1] + 1); // 일반 도로
        }
        for (const auto& shortcut : shortcuts) {
            if (shortcut.start == i && shortcut.end <= D && dist[shortcut.start] + shortcut.length < dist[shortcut.end]) {
                dist[shortcut.end] = dist[shortcut.start] + shortcut.length;
            }
        }
    }

    cout << dist[D] << endl;

    return 0;
}
