#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
	int N;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	map<int, int> check;
	int now = 0;
	check[now] = 1;
	for (int i = 1; i <= N; i++) {
		int next = (now - i);
		if (check.find(next) != check.end() || next < 0) {
			next = now + i;
		}
		check[next] = 1;
		now = next;
	}
	cout << now << "\n";
	return 0;
}
