#include<iostream>

using namespace std;

int main() {
	int n, k;
	int suffix[10005] = { 0, };
	int maxValue = 0;
	suffix[0] = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int intenseValue = 0;
		cin >> intenseValue;
		suffix[i] = suffix[i - 1] + intenseValue;
	}
	double result = 0.0;
	// k의 범위
	for (int i = k; i <= n; i++) {
		// 실제 숫자 인덱스
		for (int j = 1; j <= n - k + 1; j++) {
			double tempValue = ((double)suffix[j + i - 1] - (double)suffix[j - 1]) / (double)i;
			result = (tempValue > result) ? tempValue : result;
		}
	}
	
	//cout.unsetf(ios::fixed);
	cout.precision(10);
	cout << (double) result << endl;

	return 0;
}
