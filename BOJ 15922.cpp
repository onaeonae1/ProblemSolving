#include<iostream>
using namespace std;
int main() {
	int C;
	long long int count = 0;
	int local_start = 0 ;
	int local_end = 0;
	scanf("%d", &C);
	while (C--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (count == 0) { //초기상태
			count += (b - a);
			local_start = a;
			local_end = b;
		}
		else {
			if (a >= local_end) { //나감
				count += (b - a);
				local_start = a;
				local_end = b;
			}
			else { //겹치거나 포함임
				if (b >= local_end) { //겹침
					count += ((b-a) - (local_end-a));
					local_end = b;
				}
				else { //완벽한 포함관계 -> 갱신할 필요는 없다

				}
			}
		}
	}
	printf("%lld", count);
	return 0;
}
