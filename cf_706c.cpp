#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const long long int INF = 1e15;

string current_raw = "";
string current_rev = "";
string prev_raw = "";
string prev_rev = "";

long long int ans, current_raw_cost, current_rev_cost, prev_raw_cost, prev_rev_cost;
long long int cost[100005];

long long int get_min(long long int a, long long int b) {
	long long int retValue = a;
	retValue = a < b ? a : b;
	return retValue;
}

string do_reverse(string original) {
	string target = original;
	reverse(target.begin(), target.end());
	return target;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	current_raw_cost = 0;
	current_rev_cost = cost[1];


	cin >> current_raw;
	current_rev = do_reverse(current_raw);
	
	for (int i = 2; i <= n; i++) {
		prev_raw = current_raw;
		prev_rev = current_rev;
		prev_raw_cost = current_raw_cost;
		prev_rev_cost = current_rev_cost;
		cin >> current_raw;
		current_rev = do_reverse(current_raw);
		current_raw_cost = INF;
		current_rev_cost = INF;
	
		
		// raw comp raw
		if (current_raw >= prev_raw) {
			current_raw_cost = prev_raw_cost;
		}
		// raw comp rev
		if (current_raw >= prev_rev) {
			current_raw_cost = get_min(current_raw_cost, prev_rev_cost);
		}
		// rev comp raw
		if (current_rev >= prev_raw) {
			current_rev_cost = prev_raw_cost + cost[i];
		}
		// rev comp rev
		if (current_rev >= prev_rev) {
			current_rev_cost = get_min(current_rev_cost, prev_rev_cost + cost[i]);
		}

	}
	ans = get_min(current_raw_cost, current_rev_cost);
	ans = ans == INF ? -1 : ans;


	// cout << current_raw << endl;
	// cout << current_rev << endl;
	cout << ans << endl;
	return 0;
}
