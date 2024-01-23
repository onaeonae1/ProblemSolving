#include<iostream>
#include<deque>
using namespace std;
int N, M, K;
deque<int> A;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 1; i <= N; i++) {
		A.push_back(i);
	}
	int counter = 0;
	bool reverse = true;
	while (!A.empty()) {
		//front 빼서 back 에 넣음
		if (reverse) {
			for (int i = 0; i < K - 1; i++) {
				A.push_back(A.front());
				A.pop_front();
			}
			printf("%d\n", A.front());
			A.pop_front();
		}
		// back 빼서 front 에 넣음
		else {
			for (int i = 0; i < K - 1; i++) {
				A.push_front(A.back());
				A.pop_back();
			}
			printf("%d\n", A.back());
			A.pop_back();
		}
		counter++;
		if (counter == M) {
			reverse = !reverse;
			counter = 0;
		}
	}
	return 0;
}
