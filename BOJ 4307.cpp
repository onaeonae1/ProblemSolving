#include<iostream>
#define INF 1000005
using namespace std;
int bigger(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b; 
	}
}
int smaller(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	int N; //테스트 케이스 
	cin >> N;
	while (N--) {
		int L, M; //막대 길이와 개미의 수
		cin >> L >> M; 
		int left, right;
		int min = 0;
		int max = 0;
		while (M--) {
			int pos;
			cin >> pos;
			left = pos;
			right = L - pos;
			min = bigger(min, smaller(left, right)); //최소들 중 최대
			max = bigger(max, bigger(left, right)); //최대들 중 최대
		}
		cout << min << " " << max << endl;
	}
	return 0;
}
