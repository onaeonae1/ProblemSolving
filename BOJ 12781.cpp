#include<iostream>
#define LL long long
using namespace std;
typedef struct vector {
	LL x, y;
}V;
LL crossP(V p1, V p2, V p3) {
	LL res = 0;
	res = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
	return res;
}
int main() {
	V p[5];
	for (int i = 0; i < 4; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}
	bool result = false;
	LL cp1 = crossP(p[0], p[1], p[2]); //p1, p2, p3
	LL cp2 = crossP(p[0], p[1], p[3]); //p1, p2, p
	LL cp3 = crossP(p[2], p[3], p[0]); //p3, p4, p1
	LL cp4 = crossP(p[2], p[3], p[1]); //p3, p4, p2
	if (cp1* cp2 < 0 && cp3 * cp4 < 0){
		result = true;
	}
	if (result == true) { //교차
		printf("1");
	}
	else { //교차 x
		printf("0");
	}
	return 0;
}
