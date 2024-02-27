#include<iostream>
#include<queue>
using namespace std;
int N, T, P;
priority_queue<int> pq;

int main() {
	scanf("%d %d %d", &N, &T, &P);
	int total = 0;
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		total += temp;
		cnt++;
		pq.push(temp);

		// 현재 보고 있는 돌에서 가능한 시간
		long long rockTime = T - (long long )P * i;

		while (total > rockTime) {
			if (!cnt) {
				break;
			}
			if (rockTime < 0) {
				total = 0;
				cnt = 0;
				break;
			}
			cnt--;
			total -= pq.top();
			pq.pop();
		}

		ret = (ret < cnt) ? cnt : ret;
	}
	printf("%d", ret);
	return 0;
}
