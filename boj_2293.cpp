#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;
int DP[10005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
  DP[0] = 1;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		int now = arr[i];
		for (int j = now; j <= k; j++) {
			DP[j] += DP[j - now];
		}
	}

	cout << DP[k] <<"\n";

	return 0;
}

