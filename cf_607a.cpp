#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int table[100005];
int dp[100005];
vector<pair<int, int>> beacons;
int ans = -1;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> temp;
		temp.first = a;
		temp.second = b;
		table[i] = a;
		beacons.push_back(temp);
	}
	n = n + 1;
	sort(table, table + n);
	sort(beacons.begin(), beacons.end());
	vector<pair<int, int>>::iterator iter;
	int count = 1;
	for (iter = beacons.begin(); iter < beacons.end(); iter++) {
		pair<int, int> current = *iter;
		int a_value = current.first;
		int b_value = current.second;
		
		int target_pos = (a_value - b_value)> 0 ? a_value - b_value : 0;
		int target_index = lower_bound(table, table + n, target_pos) - table;
		
		// cout << target_index << endl;
		target_index = (target_index - 1 >= 0) ? target_index - 1 : 0;
		dp[count] = 1 + dp[target_index];
		count++;
	}
	n--;
	for (int i = 1; i <= n; i++) {
		ans = ans > dp[i] ? ans : dp[i];
		// cout << dp[i] << endl;
	}
	cout << n-ans << endl;
	return 0;
}
