#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;
int prefix[505], file[505], DP[505][505];
int main() {
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int T;
    scanf("%d", &T);
    while (T--) {
        int N; cin >> N;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &file[i]);
            prefix[i] = prefix[i - 1] + file[i];
        }
        for (int range = 1; range <= N; range++) {
            // 검색 범위
            for (int startPos = 1; startPos <= N; startPos++) {
                int endPos = startPos + range;
                if (endPos <= N) {
                    DP[startPos][endPos] = INF;
                    for (int k = startPos; k < endPos; k++) {
                        // (startPos, endPos) 사이에 있는 어떤 K든 다 끌고와봄
                        int fellow = prefix[endPos] - prefix[startPos - 1];
                        DP[startPos][endPos] = min(
                            DP[startPos][endPos],
                            DP[startPos][k] + DP[k + 1][endPos] + fellow
                        );
                    }
                }
            }

        }
        printf("%d\n", DP[1][N]);
    }
    return 0;

}
