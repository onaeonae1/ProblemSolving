#include<iostream>
using namespace std;
long long int combination(int n, int k) {
	long long int result = 1;
	long long int div = 1;
	if (k == 0 || n==0) {
		return 1;
	}
	else {
		if (n-k < k){
			k = n - k;
		}
		long long int longn = (long long int) n;
		long long int longk = (long long int) k;
		while (longk>0) {
			div*= longk; result = result * longn;
			longn--; longk--;
		}
	}
	return result/div;
}
int main() {
	int n, k;
	cin >> n >> k;
	long long int result = 1;
	result = combination(n - 1, k - 1);
	cout << result << endl;
	return 0;
}
