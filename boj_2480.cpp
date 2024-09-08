#include<iostream>
using namespace std;
int arr[10];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t = 3;
	int highestValue = 0;
	int highestDupCount = 0;
	int highstDupNumber = 0;
	while (t--) {
		int temp;
		cin >> temp;
		arr[temp]++;
		if (highestDupCount < arr[temp]) {
			highestDupCount = arr[temp];
			highstDupNumber = temp;
		}
		highestValue = (highestValue < temp) ? temp : highestValue;
	}
	int ans = 0;
	if (highestDupCount == 3) {
		ans = 10000 + highstDupNumber * 1000;
	}
	else if (highestDupCount == 2) {
		ans = 1000 + highstDupNumber * 100;
	}
	else if (highestDupCount == 1) {
		ans = highestValue * 100;
	}

	cout << ans << "\n";
	return 0;
}
