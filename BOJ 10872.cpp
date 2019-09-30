#include<iostream>
using namespace std;
int main() {
	int n;
	int fact[15] = { 1, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
	}
	printf("%d", fact[n]);
	return 0;
}
