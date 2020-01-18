#include<stdio.h>
#include <stack>
using namespace std;
int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		long long int a[100000] = { 0, };
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		stack<int> s;
		long long int ans = 0;
		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				long long int height = a[s.top()];
				s.pop();
				long long int width = i;
				if (!s.empty()) {
					width = (i - s.top() - 1);
				}
				if (ans < width*height) {
					ans = width * height;
				}
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long int height = a[s.top()];
			s.pop();
			long long int width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < width*height) {
				ans = width * height;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
