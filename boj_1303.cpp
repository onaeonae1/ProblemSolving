#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int Y, X;
int board[105][105]; 
int visit[105][105];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};
struct point{
	int y;
	int x;
};

bool isInRange(int y, int x){
	bool inY = (0<=y && y<Y);
	bool inX = (0<=x && x<X);
	return inY && inX;
}
bool isValid(int y, int x, int colour){
	if(isInRange(y,x)){
		// 방문한 적 없고 나랑 같은 colour 임
		return (!visit[y][x] && board[y][x]==colour);
	}
	else{
		return false;
	}
}
int bfs(int sty, int stx, int colour){
	// sty,stx 에서 시작해서 나랑 같은 colour 로 뭉친 애들을 구한다
	int counter = 1 ;
	visit[sty][stx] = true;
	queue<point> jobq;
	jobq.push({sty,stx});
	while(!jobq.empty()){
		point now = jobq.front();
		jobq.pop();

		int y = now.y;
		int x = now.x;

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(isValid(ny, nx, colour)){
				jobq.push({ny, nx}); 
				visit[ny][nx] = true; 
				counter++;
			}
		}
	}
	return (counter * counter);
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> X >> Y;
	for(int i=0; i<Y; i++){
		string s;
		cin >> s;
		for(int j=0; j<X; j++){
			if(s.at(j)=='W'){
				board[i][j]=1;
			}
			if(s.at(j)=='B'){
				board[i][j] = 2;
			}
		}
	}
	vector<int> ans;
	for(int colour=1; colour<=2; colour++){
		int cnt = 0;
		for(int i=0; i<Y; i++){
			for(int j=0; j<X; j++){
				if(!visit[i][j] && board[i][j]==colour){
					int temp = bfs(i,j,colour);
					cnt += temp;
					//cout << colour << " " << i << " " << j << " " << temp << " -> "<< cnt<<"\n";
				}
			}
		}
		ans.push_back(cnt);
	}
	cout << ans.front() << " "<<ans.back() << "\n";
	return 0;
}
