#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[500005];
int cnt[8005];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	int minV = 1e9; //범위(최소값)
	int maxV = -1e9; //범위(최대값)
	int sum = 0; //합
	int cnt_value = 0; // 최빈 실제 값
	int cnt_max = 0; // 최빈 등장 수
	for (int i = 0; i < N; i++) {
		int now; //일단 입력받은 값
		cin >> now;
		arr[i] = now;

		// 갯수 카운팅을 위해 다 절대값 처리함 그냥
		int cntV = now + 4000;
		cnt[cntV]++;
		if (cnt[cntV] >= cnt_max) {
			// 모르겠다 일단 갱신하고 나중에 값을 찾자
			cnt_max = cnt[cntV];
		}
		sum += arr[i];
		maxV = (maxV < arr[i]) ? arr[i] : maxV;
		minV = (minV < arr[i]) ? minV : arr[i];
	}
	sort(arr + 0, arr + N + 0);
	
	int beanCount = 0;
	for (int i = 0; i <= 8000; i++) {
		int cnt_now = i - 4000;

		if (cnt[i] == cnt_max) {
			beanCount++;
			cnt_value = cnt_now;
			if (beanCount == 2) {
				break;
			}
		}
	}

	int result = (int)(round((double)sum / N));
	cout << result << "\n";
	cout << arr[N / 2] << "\n";
	cout << cnt_value << "\n";
	cout << maxV - minV << "\n";
	return 0;
}
