#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[55];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (N == 1) {
		cout << "A\n";
		return 0;
	}
	if (N == 2) {
		if (arr[0] == arr[1])
			cout << arr[1];
		else
			cout << "A\n";

		return 0;
	}
	else {
		// 최초 값만 봐도 알지
		int a = 0;
		if (arr[1] - arr[0] != 0)
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

		int b = arr[1] - arr[0] * a;

		for (int i = 1; i < N; i++) {
			if (arr[i] != arr[i - 1] * a + b) {
				cout << "B\n";
				return 0;
			}
		}

		cout << arr[N - 1] * a + b;
	}

	return 0;
}
