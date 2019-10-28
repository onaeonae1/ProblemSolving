//can pass boj 17387 , boj 17386
#include<iostream>
#define ll long long
using namespace std;
int crossP(pair<ll, ll>p1, pair<ll, ll>p2, pair<ll, ll>p3) {
	ll res = 0;
	res = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
	if (res > 0) {
		return 1;
	}
	if (res < 0) {
		return -1;
	}
	if (res == 0) {
		return 0;
	}
}
bool check(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll>d) {
	bool ret = false;
	int cp1 = crossP(a, b, c); //a b c
	int cp2 = crossP(a, b, d); //a b d 
	int cp3 = crossP(c, d, a); //c d a
	int cp4 = crossP(c, d, b); //c d b
	if (cp1 * cp2 == 0 && cp3 * cp4 == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return a <= d && c <= b;
	}
	return cp1 * cp2 <= 0 && cp3 * cp4 <= 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	pair<ll, ll> p[5];
	for (int i = 0; i < 4; i++) {
		scanf("%lld %lld", &p[i].first, &p[i].second);
	}
	bool result = check(p[0], p[1], p[2], p[3]);
	if (result == true) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}
