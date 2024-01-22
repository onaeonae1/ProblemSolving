#include<iostream>
#include<deque>
using namespace std;
int N, M;
int A[100005];
int main() {
	int queueCount = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if (A[i] == 0) {
			queueCount++;
		}
	}
	deque<int> items = deque<int>(queueCount);
	deque<int> ans;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (A[i] == 0) {
			items.at(cnt) = temp;
			cnt++;
		}
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int cv;
		scanf("%d", &cv);
		if (queueCount == 0) {
			ans.push_back(cv);
		}
		else {
			int outValue = items.back();
			items.pop_back();
			items.push_front(cv);
			ans.push_back(outValue);
		}
	}
	deque<int>::iterator iter;
	for (iter = ans.begin(); iter < ans.end(); iter++) {
		printf("%d ", *iter);
	}
	return 0;
}
