#include<iostream>
using namespace std;
int main() {
	bool A[105] = { 0, };
	int N;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		if (A[value] == false){
			A[value] = true;
		}
		else { //A[value]==true
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
