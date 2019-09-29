#include<iostream>
#include<vector>
#include<algorithm>
#define L 1000005
using namespace std;
long long int n;
int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int triflemin(vector<int>& dice) { //3개 합 최소
	int mina = min(dice.at(0), dice.at(5));
	int minb = min(dice.at(1), dice.at(4));
	int minc = min(dice.at(2), dice.at(3));
	return (mina + minb + minc);
}
int doublemin(vector<int>& dice) { //2개 합 최소
	int ret=4*L;
	int mina = min(dice.at(0), dice.at(5));
	int minb = min(dice.at(1), dice.at(4));
	int minc = min(dice.at(2), dice.at(3));
	ret = min(ret, mina+minb);
	ret = min(ret, mina+minc);
	ret = min(ret, minb + minc);
	return ret;
}
long long int search(vector<int>& dice) {
	long long int res=0 ;
	long long alpha, beta, gamma; //3개 합 최소, 2개 합 최소, 1개 최소
	alpha = triflemin(dice); beta = doublemin(dice);
	sort(dice.begin(), dice.end());
	gamma = dice.front();
	if (n == 1) {
		for (int i = 0; i < 5; i++) { //오름차순으로 5개 싹 뽑아다 줌
			res += dice.at(i);
		}
		return res;
	}
	if (n >=2) {
		long long int head = 0;
		long long int tail = 0;
		head = alpha * 4 + beta * (4 * (n - 2));
		head += (n - 2) * (n - 2) * gamma;
		tail = beta * 4 + gamma * (4 * (n - 2));
		tail *= (n - 1);
		res = head + tail;
	}
	return res;
}
int main() {
	vector<int> dice;
	scanf("%d", &n);
	for (int i = 0; i < 6; i++) {
		int value;
		scanf("%d ", &value);
		dice.push_back(value);
	}
	long long int result = search(dice);
	printf("%lld", result);
	return 0;
}
