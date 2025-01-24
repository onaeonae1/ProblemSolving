#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int N, T;
struct Node {
	int cost, x, y, cross;
    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1} ;

bool inRange(int nx, int ny){
	bool inX = (0<=nx && nx<N);
	bool inY = (0<=ny && ny<N);
	return inY && inX;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> T;
	// init
	vector<vector<int>> grass(N, vector<int>(N));
	vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(3, 1e9)));

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> grass[i][j];
		}
	}

	Node start  = {0, 0, 0, 0};
	priority_queue<Node> jobq;
	jobq.push(start);
	dist[0][0][0] = 0;
	dist[0][0][1] = 0;
	dist[0][0][2] = 0;
	while(!jobq.empty()){
		Node now = jobq.top();
		jobq.pop();

		int currentCost = now.cost;
		int currentY = now.y;
		int currentX = now.x;
		int currentCount= now.cross;

		if(dist[currentY][currentX][currentCount%3] < currentCost){
			continue;
		}

		for(int i=0; i<4; i++){
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];
			if(inRange(nextX, nextY)){
				int nextCost = currentCost + T;
				if((currentCount+1) %3==0){
					nextCost+=grass[nextY][nextX];
				}
				if(dist[nextY][nextX][(currentCount+1)%3]> nextCost){
					dist[nextY][nextX][(currentCount+1)%3] = nextCost;
					// cout << nextY << " " <<nextX << " with cost -> " << nextCost<<"\n";
					jobq.push({nextCost, nextX, nextY, currentCount+1});
				}
			}
		}
	}

	int ret=1e9;
	for(int i=0; i<=2; i++){
		ret = min(ret, dist[N-1][N-1][i]);
	}
	cout << ret << "\n";
	return 0;
}
