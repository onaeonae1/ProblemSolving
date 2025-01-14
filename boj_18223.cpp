#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<pair<int,int>> board[5005]; // board[node] = {linkedCost, linkedNode}
int dist[5005]; // 순회 후 정리 필요
int V, E, P;
int INF = 1e8;
int dij(int start, int end){
    fill_n(dist, 5005, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> jobq;
    jobq.push({0,start});
    dist[start] = 0;

    while(!jobq.empty()){
        pair<int,int> now = jobq.top();
        jobq.pop();

        int currentCost = now.first;
        int currentNode = now.second;

        if(currentCost > dist[currentNode]){
            continue;
        }

        // 이웃 방문
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
    cin >> V >> E >> P;
    for(int i=0; i<E; i++){
        int start;
        int end;
        int value;
        cin >> start >> end >> value;
        board[start].push_back({value, end});
        board[end].push_back({value, start});
    }


    int v1 = dij(1, P);
    int v2 = dij(P,V);
    
    int save = v1 + v2;
    int optimal = dij(1,V);
    if(save<=optimal){
        cout << "SAVE HIM" << "\n";
    }
    else{
        cout << "GOOD BYE"<<"\n";
    }
    return 0;
}
