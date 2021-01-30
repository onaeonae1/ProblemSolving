#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
int n;
vector<ll> words;
int solve(int index, int state) {
	if (index == n) {
		if (state == (1 << 26) - 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	//선택, 선택안함으로 확장
	return solve(index + 1, state | words[index]) + solve(index + 1, state);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ll temp = 0;
		for (auto alpha : str) { //rnage-based auto
			temp |= 1 << (alpha - 'a');
		}
		words.push_back(temp);
	}
	printf("%d", solve(0, 0));
	return 0;
}
