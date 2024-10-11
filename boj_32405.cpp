#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<long long> parts;
vector<long long> atts;
vector<long long> hpps;
struct item {
	int idx;
	long long att;
	long long hpp;
};
deque<item> items;
long long sum = 0;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	parts.assign(N, 0);
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		atts.push_back(t);
	}
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		hpps.push_back(t);
		items.push_back({ i, atts[i], hpps[i] });
	}

	while (items.size() > 1) {
		item current = items.front();
		items.pop_front();
		int idx = current.idx;
		long long att = current.att;
		long long hpp = current.hpp;
		long long temp = sum - current.att * parts[idx];
		bool isValid = (hpp>temp);
		if (isValid) {
			parts[idx]++;
			sum += att;
			items.push_back(current);
		}
	}
	
	cout << items.front().idx + 1 << "\n";
	return 0;
}
