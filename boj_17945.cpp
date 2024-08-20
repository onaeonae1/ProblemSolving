#include<iostream>
using namespace std;
int main() {
	int a, b; 
	scanf("%d %d", &a, &b);
	for (int i = -1000; i <= 1000; i++) {
		int t = (i * i) + (2 * a * i) + b;
		if (t == 0) { printf("%d ", i); }
	}
	return 0;
}
