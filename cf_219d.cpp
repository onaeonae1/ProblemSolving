#include<iostream>
#include<vector>
using namespace std;
class Node {
public: 
	int parent;
	int lowSum; //아래쪽 기준으로 sum
	int totalSum;
	vector<int> adjanct; //인접한 child
	vector<int> direcction; //방향
	vector<int> reverseCount; //아래쪽으로 역 필요한 것 계산
};
Node city[200005];
int n;
int ORTH = 0;
int REV = 1;
int MAX = 99999999;
int dfs1(int num, int parent) {
	//아래 쪽에서 받아서 올림
	int retValue = 0;
	Node& now = city[num];
	now.parent = parent;
	int size = now.adjanct.size();
	for (int i = 0; i < size; i++) {
		if (now.adjanct[i] != now.parent) {
			now.reverseCount[i] = dfs1(now.adjanct[i], num);
		}
	}
	for (int i = 0; i < size; i++) {
		if (now.adjanct[i] != now.parent) {
			int revNeeded = now.direcction[i];
			retValue += revNeeded + now.reverseCount[i];
		}
	
	}
	now.lowSum = retValue;
	return retValue;
}
void dfs2(int num, int parent, int highSum, int direction) {
	//위의 답을 받아서 처리
	Node& now = city[num];
	int size = now.adjanct.size();
	if (parent == 0) { // 루트인 경우
		now.totalSum = now.lowSum;
	}
	else {
		if (direction == 0) {
			// 위에서 아래로 들어옴 (뒤집을 필요 O)
			now.totalSum = highSum + 1;
		}
		else {
			//아래에서 위로 뻗어나감(뒤집음 필요X) -> 중복 제거
			now.totalSum = highSum - 1;
		}
	}
	for (int i = 0; i < size; i++) {
		if (now.adjanct[i] != now.parent) {
			dfs2(now.adjanct[i], num, now.totalSum, now.direcction[i]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		city[x].adjanct.push_back(y);
		city[x].direcction.push_back(ORTH);
		city[x].reverseCount.push_back(0);
		city[y].adjanct.push_back(x);
		city[y].direcction.push_back(REV);
		city[y].reverseCount.push_back(0);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0, 0);
	int ans = MAX;
	for (int i = 1; i <= n; i++) {
		if (ans >= city[i].totalSum) {
			ans = city[i].totalSum;
		}
	}
	vector<int> pos;
	for (int i = 1; i <= n; i++) {
		if (city[i].totalSum == ans) {
			pos.push_back(i);
		}
	}
	cout << ans << endl;
	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i] << " ";
	}
	cout << "" << endl; 
	return 0;
}
