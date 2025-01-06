#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int,int>> board[805]; // board[node] = {linkedCost, linkedNode}
int dist[805]; // 순회 후 정리 필요
int N, E;
int t1, t2;
int INF = 1e8;
int dij(int start, int end){
    fill_n(dist, 805, INF);

    priority_queue<pair<int,int>> jobq; // {cost, node} 
    jobq.push({0,start});
    visit[start] = 1;
    dist[start] = 0;

    while(!jobq.empty()){
        pair<int,int> now = jobq.top();
        jobq.pop();

        int currentCost = now.first;
        int currentNode = now.second;

        if(currentCost > dist[currentNode]){
            continue;
        }
        for(int i=0; i<board[currentNode].size(); i++){
            int node = board[currentNode][i].second;
            int cost = board[currentNode][i].first;
            int nextCost = currentCost + cost;

            if(nextCost < dist[node]){
                dist[node] = nextCost;
                jobq.push({nextCost, node});
            }
        }
    }

    return dist[end];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> E;
    for(int i=0; i<E; i++){
        int start;
        int end;
        int value;
        cin >> start >> end >> value;
        board[start].push_back({value, end});
        board[end].push_back({value, start});
    }
    cin >> t1 >> t2;

    int common = dij(t1, t2);
    int v1 = dij(1,t1) + common + dij(t2,N);
    int v2 = dij(1,t2) + common + dij(t1,N);

    int ans = (v1<v2) ? v1 : v2;
    ans = (ans>=INF) ? -1 : ans;
    cout << ans << "\n";
    return 0;
}
