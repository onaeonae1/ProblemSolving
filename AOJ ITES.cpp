#include<iostream>
#include<queue>
using namespace std;
struct RNG {
	unsigned seed;
	RNG() : seed(1983) {

	}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011);
		return ret % 10000 + 1;
	}
};
int countRanges(int k, int n) {
	RNG rng;
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);
		while (rangeSum > k) {
			rangeSum -= range.front();
			range.pop();
		}
		if (rangeSum == k) {
			ret++;
		}
	}
	return ret;
}
int main() {
	int c; 
	int results[25] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		int n, k;
		cin >> n >> k;
		results[index] = countRanges(n, k);
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
}
