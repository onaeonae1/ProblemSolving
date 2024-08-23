#include<iostream>
#include<vector>
#include<queue>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> left;
	priority_queue<int, vector<int>, greater<int>> right;
	vector<int> answers;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		// 일단 push
		if (i% 2 == 0) {
			left.push(temp);
		}
		else {
			right.push(temp);
		}
		// 교환
		if (left.size() > 0 && right.size() > 0) {
			int leftTop = left.top();
			int rightTop = right.top();
			if (leftTop > rightTop) {
				// 야 이거 역전이다
				left.pop();
				right.pop();
				left.push(rightTop);
				right.push(leftTop);
			}
		}

		// 정답 찾기 -> 왼쪽 끝
		answers.push_back(left.top());
	}
	for (int i : answers) {
		cout << i << "\n";
		//printf("%d\n", i);
	}
	return 0;
}
