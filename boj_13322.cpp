#include <iostream>
#include <string>
using namespace std;
string s;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	N = s.length();
	for (int i = 0; i < N; i++) {
		cout << i << '\n';
	}
	return 0;
}
