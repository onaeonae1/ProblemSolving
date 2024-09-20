#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> items;
int N, M, L;
bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int dist = items[i] - items[i - 1];
        cnt += dist / mid;
        if (dist % mid == 0) {
            cnt--;
        }
    }
    return cnt > M;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> L;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        items.push_back(t);
    }
    items.push_back(0);
    items.push_back(L);
    sort(items.begin(), items.end());
    N+=2;
    int start = 1;
    int end = L;
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        bool isOver = check(mid);
        if (isOver) {
            start = mid + 1;
        }
        else {
            ans = mid;
            end = mid-1;
        }
    }
    cout << ans << "\n";
    return 0;
}
