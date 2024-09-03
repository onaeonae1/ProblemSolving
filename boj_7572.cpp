#include<iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	char a = 'A' + (N + 8) % 12;
	char b = '0' + (N + 6) % 10;
	cout << a << "" << b << "\n";
	return 0;
}
