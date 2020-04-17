#include<iostream>
#include<algorithm>
#include<string>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, vector<string>> edge; //정점
unordered_map<string, int> visited;
vector<string> animalList;
void dfs(unordered_map<string, vector<string>>::iterator it) {
	//dfs 의 실행은 방문한 적이 없는 정점임이 보장됨.
	//현재 정점과 연결된 다른 정점들 확인하기.
	for (int i = 0; i < it->second.size(); i++) {
		string element = it->second[i];
		unordered_map<string, vector<string>>::iterator next = edge.find(element); //다음 정점 iterator
		if (visited[element] == 0) { //이친구는 방문한 적이 없다.
			//b로만 등장한 정점이 있을 수 있기 때문에 여기서 방문체크/정답추가를 해준다.
			animalList.push_back(element);
			visited[element] = 1;
			if (next != edge.end()) {
				dfs(next);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b, c; cin >> a >> c >> b;
		edge[a].push_back(b);
		visited[a] = 0;
		visited[b] = 0;
	}
	auto it = edge.find("Baba");
	if (it!= edge.end()) {
		//animalList.push_back("Baba"); //Baba는 그냥 넣어도 무관하다.
		dfs(it);
		sort(animalList.begin(), animalList.end());
	}
	for (int i = 0; i < animalList.size(); i++) {
		cout << animalList[i] << '\n';
	}
	return 0;
}
