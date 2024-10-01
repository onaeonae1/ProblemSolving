#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	long long sum=0;
	vector<long long> items;
	cin >> N;
	long long t1 = 0;
	long long t2 = 0;
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		sum += t;
		items.push_back(t);
	}
	long long average = sum / N;
	for (int i = 0; i < items.size(); i++) {
		long long height = items[i];
		if (height > average) {
			t1 += (height-average - 1);
		}
		else {
			t2 += (average - height);
		}
	}
	long long ans = (t1 < t2) ? t2 : t1;
	cout << ans << "\n";
	return 0;
}
