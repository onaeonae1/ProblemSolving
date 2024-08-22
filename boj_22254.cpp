#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<int> items(100005);
bool isValidTarget(int target) {
	priority_queue<int, vector<int>, greater<int>> pq;
	bool validTarget = true;
	// 공정 TARGET 개 만큼 push
	for (int i = 0; i < target; i++) {
		pq.push(0);
	}
	for (int i = 0; i < N; i++) {
		// n만큼 순회하면서 때려줍시다
		int current = pq.top();
		pq.pop();
		int next = current + items[i];
		if (next > M) {
			// 먼 짓을 해도 이 target 으로는 안됩니다
			validTarget = false;
			break;
		}
		// 어 아무튼 난 queue 에 넣을테니깐 계속 돌아봐
		pq.push(next);
	}
	return validTarget;

}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> items[i];
	}

	// 2개의 공정에서 최대 값?
	// 전체 넣고 2개씩 pop 해서 최대를 구하면 됨

	int start = 1;
	int end = N;
	int ans = N;

	while (start <= end) {
		int target = (start + end) / 2;
		bool validTarget = isValidTarget(target);
		if (validTarget) {
			// 처리 됨 & target 을 줄여봐
			ans = (ans < target) ? ans : target;
			end = target - 1;
		}
		else {
			// 처리가 안된다는데? start를 늘려봐
			start = target+1;
		}
	}
	cout << ans << endl;
    return 0;
}
