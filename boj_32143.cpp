#include<queue>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int H, N, Q; 
    cin >> H;
    cin >> N >> Q;
    priority_queue <int, vector <int>, greater<int>> pq;
    long sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
        sum += x;
    }

    // 최초 확인
    while (sum - pq.top() >= H) {
        sum -= pq.top();
        pq.pop();
    }
    if (sum < H) {
        cout << -1 << "\n";
    }
    else {
        cout << pq.size() << "\n";
    }
    // 이후엔 쿼리 따라서 움직인다
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        pq.push(t);
        sum += t;
        while (sum - pq.top() >= H)
        {
            sum -= pq.top();
            pq.pop();
        }

        if (sum < H) {
            cout << -1 << "\n";
        }
        else {
            cout << pq.size() << "\n";
        }
    }
    return 0;
}
