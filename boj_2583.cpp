#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int a, b, c, d;
int M, N, K;
int ans = 0;
bool visit[101][101];
vector<int> ret;

void bfs(int sty, int stx) {
    queue<pair<int, int>> q;
    q.push({ sty, stx });
    visit[sty][stx] = true;
    int cnt = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < N && nx >= 0 && ny < M && ny >= 0) {
                if (!visit[ny][nx]) {
                    q.push({ ny, nx });
                    visit[ny][nx] = true;
                    cnt++; 
                }
            }
        }
    }
    ret.push_back(cnt);
}
int main() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c >> d;
        for (int r = b; r < d; r++) { 
            for (int l = a; l < c; l++) { 
                visit[r][l] = true; 
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
                ans++; 
            }
        }
    }
    cout << ans << '\n';
    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    return 0;
}
