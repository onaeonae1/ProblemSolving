#include<iostream>

using namespace std;

long long int suffix[500005];

int main() {
	int n;
	cin >> n;

	long long int totalValue;
	long long int thirdValue;
	long long int pivotValue;

	long long int answerCount = 0;
	long long int thirdCount = 0;

	for (int i = 1; i <= n; i++) {
		long long int tempValue;
		cin >> tempValue;
		suffix[i] = suffix[i - 1] + tempValue;
	}

	totalValue = suffix[n];

	if (totalValue % 3 != 0) {
		answerCount = 0;
	}
	else {
		thirdValue = totalValue / 3;
		pivotValue = thirdValue * 2;
		for (int i = 1; i < n; i++) {
			if (suffix[i] == pivotValue) {
				answerCount += thirdCount;
			}
			if (suffix[i] == thirdValue) {
				thirdCount += 1;
			}
		}
	}

	cout << answerCount;

	return 0;
}
