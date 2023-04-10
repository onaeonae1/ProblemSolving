#include<iostream>
#define MIN -1
#define MAX 100005
using namespace std;
int n;
int A[100005];

int main(void) {
	int minPos = -1;
	int maxPos = -1;
	int maxValue = MIN;
	int minValue = MAX;
	int count = 0;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		int currentValue = A[i];
		int tempValue = (maxValue == minValue) ? i : 0;
		if (
			(maxValue!=-1 && minValue!=-1)&&
			(currentValue == minValue - 1 || currentValue == maxValue + 1)
		) {
			if (currentValue == minValue - 1) {
				// minValue needs to be updated
				count = (i - maxPos) + tempValue;
				maxValue = minValue;
				minValue = minValue - 1;
				maxPos = minPos;
				minPos = i;
			}
			if (currentValue == maxValue + 1) {
				//maxValue needs to be updated
				count = (i - minPos) + tempValue;
				minValue = maxValue;
				maxValue = maxValue + 1;
				minPos = maxPos;
				maxPos = i;
			}
		}
		else {
			maxValue = maxValue <= currentValue ? currentValue : maxValue;
			minValue = minValue >= currentValue ? currentValue : minValue;
			if (currentValue == maxValue) {
				maxPos = i;
			}
			if (currentValue == minValue) {
				minPos = i;
			}
			count++;
		}
		ans = ans <= count ? count : ans;
		// cout << "(i : " << i << " : count: " << count << ")" << endl;
	}
	cout << ans << endl;
	return 0;
}
