#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> positive;
vector<int> negative;
int zeroCnt = 0;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
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
	sort(negative.begin(), negative.end(), greater<int>()); // // 마찬가지로 큰 순


	int s = 0;
	while (positive.size() > 1) {
		int a = positive.back();
		positive.pop_back();
		int b = positive.back();
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
		int t = positive.back();
		s += t;
		positive.pop_back();
	}
	while (negative.size() > 1) {
		int a = negative.back();
		negative.pop_back();
		int b = negative.back();
		negative.pop_back();
		s += (a * b);
	}
	while (negative.size() > 0) {
		int t = negative.back();
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
