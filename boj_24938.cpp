#include<iostream>
#include<vector>
using namespace std;
long long sum = 0;
long long ans = 0;
vector<long long> items;
int N;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long temp;
		cin >> temp;
		items.push_back(temp);
		sum += temp;
	}
	long long target = sum / N;
	N--;
	for (int i = 0; i < N; i++) {
		long long & x = items[i];
		long long &y = items[i + 1];
		long long  temp = target - x;
		ans += abs(temp);
		y -= temp;
	}

	cout << ans << "\n";
	return 0;
}
