#include<iostream>
#include<climits>
using namespace std;
int ropes[10005];
int K, N;
int cutting(int X) { // 길이 X로 잘랐을 때
	int count = 0;
	for (int i = 0; i < K; i++) {
		count += (ropes[i] / X);
	}
	return count;
}
long long int binSearch(long long int start, long long int end) {
	long long int ret = 0;
	while (start <= end) {
		long long int X = (start + end) / 2;
		long long int res = cutting(X);
		if (res >= N) { //갯수 많거나 같음
			if (ret <= X) { //가능한 자르기 길이 갱신
				ret = X;
			}
			start = X + 1;
		}
		else { //갯수 적음
			end = X - 1;
		}
	}
	return ret;
}
int main() {
	cin >> K >> N;
	long long int rear =INT_MAX;
	for (int i = 0; i < K; i++) {
		cin >> ropes[i];
	}
	long long int result = binSearch(0, rear);
	cout << result << endl;
	return 0;
}
