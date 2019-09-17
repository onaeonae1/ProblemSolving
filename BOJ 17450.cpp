#include<iostream>
using namespace std;
int main() {
	char name[3] = { 'S', 'N', 'U' };
	double max = -1;
	int flag=0;
	for (int i = 0; i < 3; i++) {
		double value, weight; //가격 그리고 무게
		cin >> value >> weight;
		value = value * 10; //10봉지의 가격
		weight = weight * 10; //10 봉지의 무게
		if (value>= 5000) {
			value -= 500; //쿠폰 적용
		}
		double temp = weight / value;
		if (temp > max) {
			max = temp;
			flag = i;
		}
	}
	cout << name[flag] << endl;
	return 0;
}
