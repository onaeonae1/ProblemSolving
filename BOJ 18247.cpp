#include<iostream>
using namespace std;
int main() {
	int c;
	cin >> c;
	while (c--) {
		int result = -1;
		int n, m;
		cin >> n >> m;
		if (n >= 12 && m >= 4) {
			result = 11 * m + 4;
		}
		cout << result << endl;
	}
	return 0;
}
