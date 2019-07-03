#include<iostream>
#include<deque>
#include<vector>
using namespace std;
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	deque<pair<int, int> > A;
	//first : 값
	//second : 합
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		pair<int, int > temp;
		temp.first = value;
		temp.second = value;
		A.push_front(temp);
	}
	int result = 0; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i].first > A[j].first) { //더할 수 있다.
				A[i].second = max(A[i].second, A[i].first + A[j].second);
			}
		}
		result = max(result, A[i].second);
	}
	cout << result << endl;
}
