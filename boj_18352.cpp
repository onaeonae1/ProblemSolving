#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K, X;
vector<int> adj[300005];
vector<int> ans;
bool visit[300005];
struct point{
	int pos;
	int cnt;
};
void bfs(){
	queue<point> jobq;
	jobq.push({X, 0});
	visit[X] = true;
	while(!jobq.empty()){
		point now = jobq.front(); 
		jobq.pop();

		int pos = now.pos;
		int cnt = now.cnt;

		if(cnt==K){
			ans.push_back(pos);
			continue;
		}
		for(int next : adj[pos]){
			if(!visit[next]){
				jobq.push({next, cnt+1});
				visit[next]=true;
			}
			
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M >> K >> X;
	while(M--){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	bfs();
	if(ans.size()==0){
		cout << -1 << "\n";
	}
	else{
		sort(ans.begin(), ans.end());
		for(int i : ans){
			cout << i << "\n";
		}
	}
	return 0;
}
