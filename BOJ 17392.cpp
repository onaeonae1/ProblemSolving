#include<iostream>
using namespace std;
int squaresum(int a) {
	return (a * (a + 1) * (2 * a + 1) / 6); 
}
int main() {
	int n, m;
	int count = 0;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int value;
		cin >> value; 
		m -= (value + 1);
	}
	if (m <= 0) { //우울한 날이 없다
		count = 0;
	}
	else { //n+1 칸 모두 사용해야
		int mod = m % (n + 1); //최대로 긴 우울한 날의 범위
		int div = m / (n + 1); //그러한 범위가 등장하는 수
		count = squaresum(div + 1) * mod + squaresum(div) * (n + 1 - mod);
	}
	cout << count << endl;
	return 0;
}
