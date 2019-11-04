#include<iostream>
using namespace std;
int n;
int result;
void engine(int pos, int num, int sum) {
	if (pos == n) { //꺼야할때
		if (sum % 3 == 0) {
			result++;
		}
		return;
	}
	else {
		engine(pos + 1, 0, sum);
		engine(pos + 1, 1, sum + 1);
		engine(pos + 1, 2, sum + 2);
	}
}
int main() {
	scanf("%d", &n);
	engine(1, 1, 1); //1번째 자리에 1을 넣고 sum은 1
	engine(1, 2, 2); //1번째 자리에 2를 넣고 sum은 2
	printf("%d\n", result);
	return 0;
}
