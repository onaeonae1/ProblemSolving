#include <iostream>
using namespace std;
struct li {
	int st, fin;
	int d;
};
int n, l;//d==0 -> d==1 <-

int main() {
	scanf("%d%d\n", &n, &l);
	li *lin = new li[n];
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b == 0)
			lin[i].st = 0, lin[i].fin = a, lin[i].d = 0;
		else
			lin[i].st = l - a, lin[i].fin = l, lin[i].d = 1;
	}
	int ans = 0;
	int idx = 0;
	while (1) {
		for (int i = idx; i < n - 1; i++) {
			if (lin[i].st<=lin[i+1].fin && lin[i+1].fin<=lin[i].fin) {
				idx = i + 1;
			}
			else if (lin[i+1].st<=lin[i].fin && lin[i].fin<=lin[i+1].fin) {
				idx = i+1;
			}
			else break;
		}
		if (idx == n - 1) break;
		ans++;
		for (int i = idx; i < n; i++) {
			if (lin[i].fin - lin[i].st == l) continue;
			if (lin[i].d == 0) {
				lin[i].st += 1;
				lin[i].fin += 1;
				if (lin[i].fin == l)
					lin[i].d = 1;
			}
			else {
				lin[i].st -= 1;
				lin[i].fin -= 1;
				if (lin[i].st == 0)
					lin[i].d = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
