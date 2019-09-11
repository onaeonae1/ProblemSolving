#include<iostream>
using namespace std;
int main() {
	long long int N, K, assume; 
	long long int tencounter = 1; 
	long long int sum = 0;
	long long int count = 9; 
	long long int length = 1;
	long long int answer = -1;
	cin >> N >> K;
	assume = K;
	while (assume > count * length) {
		sum += count;
		assume -= count * length;
		count *= 10;
		length++;
	}
	sum += (assume-1) / (length) + 1;
	if (sum > N) { //터짐
		answer = -1; 
	}
	else {
		long long alpha = (assume - 1) % length + 1;
		for (int i = 0; i < length-1; i++) {
			tencounter *= 10;
		}
		for (int i = 0; i < alpha; i++) {
			answer = sum / tencounter;
			sum %= tencounter;
			tencounter /= 10;
		}
	}
	cout << answer << endl;
	return 0;
}
