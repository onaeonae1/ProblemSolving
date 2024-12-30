#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int S;
bool isVisit[1000005];
pair<int, int> visit[1000005]; // visit[i] = {visitCount, beforeValue}

bool isValid(int value, int cost) {
    return !isVisit[value] || visit[value].first > cost;
}

void process(queue<pair<int, int>>& jobq, int nowValue, int nowCost, int nextValue) {
    int cost = nowCost + 1;
    if (isValid(nextValue, cost)) {
        jobq.push({ nextValue, cost });
        visit[nextValue] = { nowCost, nowValue };
        isVisit[nextValue] = true;
    }
}

void bfs() {
    queue<pair<int, int>> jobq;
    jobq.push({ S, 0 });
    isVisit[S] = true;
    visit[S] = { 0, S };

    while (!jobq.empty()) {
        pair<int, int> now = jobq.front();
        int nowValue = now.first;
        int nowCost = now.second;
        jobq.pop();

        if (nowValue == 1) {
            break;
        }

        if (nowValue % 3 == 0) process(jobq, nowValue, nowCost, nowValue / 3);
        if (nowValue % 2 == 0) process(jobq, nowValue, nowCost, nowValue / 2);
        process(jobq, nowValue, nowCost, nowValue - 1);
    }

    vector<int> ret;
    for (int t = 1; t != S; t = visit[t].second) {
        ret.push_back(t);
    }
    ret.push_back(S);

    cout << ret.size() - 1 << "\n";
    for (auto it = ret.rbegin(); it != ret.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> S;
    bfs();
    return 0;
}
