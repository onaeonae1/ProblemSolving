#include<iostream>
#include<algorithm>
#define N 5000005
#define Z 26
using namespace std;
int str[N] = { 0, };
int main() {
	int n, m; //길이, 가치
	scanf("%d %d", &n, &m);
	int sum = n;
	//예외처리
	if (m < n || m >(26 * n)) {
		printf("!");
		return 0;
	}
	//일단 1로 다 채워
	for (int i = 0; i < n; i++) {
		str[i] = 1;
	}
	int now = n - 1;
	while (sum < m) {
		int diff = m-sum;
		if (diff > Z) { //아직 26보다 더 남았기 때문에 Z박고 더 진행해야댐
			sum += Z-1; //A지우니까 -1 해주고 더해줌
			str[now] = Z;
			now--;
		}
		else { //26보다 작거나 같음 -> diff만큼 변경해주면 됨
			sum += diff;
			str[now] += diff;
			now--;
		}
	}
	sort(str, str + n);
	for (int i = 0; i < n; i++) {
		printf("%c", (str[i] - 1) + 'A');
	}
	return 0;
}
