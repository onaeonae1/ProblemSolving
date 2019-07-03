#include<iostream>
using namespace std;
double cross(double Z, double O, double p1, double p2) {
	double temp1 = Z * p1;
	double temp2 = O * p2;
	return (temp1 + temp2);
}
int main() {
	int N, M; //일자의 수, 현재 기분
	double nowZero, nowOne;
	double a, b, c, d;

	cin >> N >> M;
	cin >> a >> b >> c >> d;
	if (M == 1) {
		nowOne = 1.0; nowZero = 0.0;
	}
	else {
		nowOne = 0.0; nowZero = 1.0;
	}

	for (int i = 1; i <= N; i++) {
		double alpha = cross(nowZero, nowOne, a, c);
		double beta = cross(nowZero, nowOne, b, d);
		nowZero = alpha;
		nowOne = beta;
	}
	double retZero = nowZero * 1000;
	double retOne = nowOne * 1000;
	/*  <double의 반올림 관련 참고>
	printf("%0.f", 456.5); //456 출력
	printf("%0.f", 456.51); //457 출력
	*/
	printf("%d\n", (int)(retZero + 0.5));
	printf("%d\n", (int)(retOne + 0.5));
	return 0;
}
