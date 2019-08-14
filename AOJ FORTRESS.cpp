#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; //성벽갯수
struct circle {
	int x; //x점
	int y; //y점
	int rad; //반지름
}wall[105];
struct TreeNode {
	vector<TreeNode*> children;
};
//제곱 계산 후 리턴
int square(int v) {
	return v * v;
}
//두 성벽의 중심점 간 거리 리턴
int distance(int a, int b) {
	int value = 0;
	value = square(wall[a].x - wall[b].x) + square(wall[a].y - wall[b].y);
	return value;
}
//성벽 a 가 성벽 b를 포함하는지
bool encloses(int a, int b) {
	return (wall[a].rad > wall[b].rad) && (distance(a, b) < square(wall[a].rad - wall[b].rad));
}
//트리에서 parent가 child의 부모인지 확인 parent는 child를 포함하는 성벽이어야 함
bool isChild(int parent, int child) {
	if (encloses(parent, child) == false) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i != parent && i != child && encloses(parent, i) && encloses(i, child)) {
				return false;
			}
		}
	}
	return true;
}
//root 기준으로 서브트리 생성
TreeNode* getTree(int root) {
	TreeNode * ret = new TreeNode();
	for (int ch = 0; ch < n; ch++) {
		if (isChild(root, ch)==true) { //root가 ch번 성벽을 포함
			ret->children.push_back(getTree(ch));
		}
	}
	return ret;
}
int longest;
//root의 높이 계산
int height(TreeNode * root) {
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++) {
		heights.push_back(height(root->children[i]));
	}
	if (heights.empty() == true) {
		return 0;
	}
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2) {
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	}
	return heights.back() + 1;
}
//트리에서의 최대 길이 계산
int solve(TreeNode* root) {
	longest = 0;
	int h = height(root);
	return max(longest, h);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int c;
	int index = 0;
	int results[105] = { 0, };
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> wall[i].x >> wall[i].y >> wall[i].rad;
		}
		TreeNode* Tree = getTree(0); //0번 성벽을 루트로 트리 생성
		results[index] = solve(Tree);
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
