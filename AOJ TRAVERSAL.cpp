#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> slice(const vector<int> &v, int a, int b) {
	//vector v 의 a~b까지의 요소만 잘라서 리턴 
	return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	//노드의 수
	const int N = preorder.size();
	//텅빈 루트 일때는 리턴
	if (preorder.empty()==true) {
		return;
	}
	const int root = preorder.front();
	//트리의 왼쪽 서브트리의 크기 -> inorder에서 루트의 위치를 찾아서 알 수 있음
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - 1 - L;
	//루트 기준 왼쪽 서브트리 postorder
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	//루트 기준 오른쪽 서브트리 postorder
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	//postorder에서 루트는 마지막에 순회함
	cout << root <<" ";
}
int main() {
	int c;
	cin >> c;
	while (c--) {
		vector<int> preorder;
		vector<int> inorder;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;
			preorder.push_back(value);
		}
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;
			inorder.push_back(value);
		}
		printPostOrder(preorder, inorder);
		cout << "" << endl;
	}
	return 0;
}
