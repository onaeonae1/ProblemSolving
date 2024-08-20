#include<iostream>
using namespace std;
int items[100005];
int main() {	
	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, M;
	int sum = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> items[i];
		sum += items[i];
	}
	int lowValue = 0;
	int highValue = sum;
	int ans = 0;

	while (lowValue <= highValue) {
		// 일단 순회
		int targetValue = (lowValue + highValue) / 2;
		int overGroup = 0;
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += items[i];
			if (sum >= targetValue) {
				// 목표치를 넘기는 그룹을 찾았음
				// sum 초기화 -> 새로운 그룹이라는 뜻
				overGroup++;
				sum = 0;
			}
			if (overGroup >= M) {
				// 목표치를 넘기는 그룹이 k 보다 많이 생성됨
				// 일단 이 값으로의 분할은 무조건 가능함
				// 따라서 정답 갱신 및 목표치의 오른쪽으로 이동
				ans = (ans < targetValue) ? targetValue : ans;
				lowValue = targetValue + 1;
				break;
			}
		}
		if (overGroup < M) {
			// 앞서 for문에서 못찾았다고 가정
			highValue = targetValue - 1;
		}
	}

	cout << ans << endl;

	return 0;
}
