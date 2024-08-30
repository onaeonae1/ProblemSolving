#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int T, N;
struct proc {
    int pid;
    int cost;
    int priority;
};
bool sort_compare(const proc& a, const proc& b) {
    if (a.priority == b.priority) {
        return a.pid < b.pid;
    }
    else {
        return a.priority > b.priority;
    }
}

struct pq_cmp {
    bool operator()(proc a, proc b) {
        if (a.priority == b.priority) {
            return a.pid > b.pid;
        }
        else {
            return a.priority < b.priority;
        }
    }
};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(false);
    priority_queue<proc, vector<proc>, pq_cmp> pq;
    vector<proc> items;
    cin >> T >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        items.push_back({ a,b,c });
    }
    sort(items.begin(), items.end(), sort_compare);
    for (int i = 0; i < N; i++) {
        pq.push(items[i]);
    }

    while (T-- && !pq.empty()) {
        proc top = pq.top();
        pq.pop();
        int pid = top.pid;
        int cost = top.cost;
        int priority = top.priority;
        cout << pid << "\n";
        priority--;
        cost--;
        if (cost > 0) {
            // 이 친구는 계속 갑니다
            pq.push({ pid, cost, priority });
        }
    }
    return 0;
}
