#include<iostream>
#include<deque>
using namespace std;
int N, L;
int items[5000005];
deque <pair<int, int>> window; //idx, value
int main() {
	scanf("%d %d", &N, &L);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &items[i]);
	}

	for (int i = 1; i <= N; i++) {
		int temp = items[i];
		if (window.empty() == false) {
			// 최소값으로 존재하시는 분이 idx에 결함이 있다
			if (window.front().first < i - L + 1) {
				window.pop_front();
			}
		}
		while (window.empty() == false && window.back().second > temp) {
			window.pop_back();
		}

		window.push_back(make_pair(i, temp));
		printf("%d ", window.front().second);
	}
	
	return 0;
}
