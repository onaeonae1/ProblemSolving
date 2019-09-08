#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int L = 5000000 + 1;
int check[L]; //체
//체 설정
void primeSet() {
	for (int i = 2; i < L; i++) { //증감
		check[i] = i;
	}
	for (int i = 2; i*i < L; i++) {
		if (check[i] == i) {
			for (int j = i * i; j < L; j += i) { //실제 이동
				if (check[j] == j) {
					check[j] = i;
				}
			}
		}
	}
}
//소인수 분해
void div(int E, vector<int>& result) {
	while (E > 1) {
		result.push_back(check[E]);
		E /= check[E];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	primeSet();
	vector<int> result;
	int N;
	cin >> N;
	while (N--) {
		int E;
		cin >> E;
		div(E, result);
		for (int i = 0; i < result.size(); i++) {
			printf("%d ", result.at(i));
		}
		printf("\n");
		result.clear();
	}
	return 0;
}
