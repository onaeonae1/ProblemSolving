#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> positive;
vector<long long> negative;
int zeroCnt = 0;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long t;
		cin >> t;
		if (t == 0) {
			zeroCnt++;
		}
		else if (t > 0) {
			positive.push_back(t);
		}
		else if (t < 0) {
			negative.push_back(t);
		}
	}
	sort(positive.begin(), positive.end()); // 그냥 오름차순
	sort(negative.begin(), negative.end(), greater<long long>()); // // 마찬가지로 큰 순


	long long s = 0;
	while (positive.size() > 1) {
		long long  a = positive.back();
		positive.pop_back();
		long long b = positive.back();
		positive.pop_back();
		if (a == 1 || b == 1) {
			s += a;
			s += b;
		}
		else {
			s += (a * b);
		}
	}
	while (positive.size() > 0) {
		long long t = positive.back();
		s += t;
		positive.pop_back();
	}
	while (negative.size() > 1) {
		long long a = negative.back();
		negative.pop_back();
		long long b = negative.back();
		negative.pop_back();
		s += (a * b);
	}
	while (negative.size() > 0) {
		long long t = negative.back();
		negative.pop_back();
		if (zeroCnt > 0) {
			zeroCnt--;
		}
		else {
			s += t;
		}
	}

	cout << s << "\n";
	return 0;
}
