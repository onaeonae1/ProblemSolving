#include<iostream>
#include<queue>
using namespace std;
int X, Y, Z;
int ans = -1;
int visited[105][105][105];
int board[105][105][105];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct point{
	int z;
	int y;
	int x;
};
queue<pair<point, int>> q;
bool checkInRange(int z, int y, int x){
    bool inZrange = (0<=z && z<Z);
	bool inYrange = (0<=y && y<Y);
	bool inXrange = (0<=x && x<X);
    return (inZrange && inYrange && inXrange);
}
bool checkValid(int z, int y, int x){
    if(checkInRange(z,y,x)){
        bool isBlank = board[z][y][x] ==-1;
	    bool isVisited = visited[z][y][x];
        return ((!isBlank) && (!isVisited));
    }
    else{
        return false;
    }

}
void bfs(){
	while(!q.empty()){
		// Q 안에는 valid 한 point 만이 들어온다
		pair<point, int> now = q.front();
		q.pop();
		int z = now.first.z;
		int y = now.first.y;
		int x = now.first.x;
		int cost = now.second;
		board[z][y][x] = 1;
		for(int i=0; i<6; i++){
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(checkValid(nz, ny, nx)){
				q.push({{nz, ny, nx}, cost+1});
				visited[nz][ny][nx] = true;
			}
		}
		ans = (ans > cost) ? ans : cost;
	}
    for(int i=0; i<Z; i++){
        for(int j=0; j<Y; j++){
            for(int k=0; k<X; k++){
                if(board[i][j][k]==0){
                    ans= -1;
                    return;
                }
            }
        }
    }
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> X >> Y >> Z;
	for(int i=0; i<Z; i++){
		for(int j=0; j<Y; j++){
			for(int k=0; k<X; k++){
				cin >> board[i][j][k];
				if(board[i][j][k]==1){
					q.push({{i,j,k}, 0});
					visited[i][j][k] = true;
				}
				else if(board[i][j][k]==-1){
					visited[i][j][k]=true;
				}
			}
		}
	}
    bfs();
	cout << ans << "\n";
	return 0;
}	
