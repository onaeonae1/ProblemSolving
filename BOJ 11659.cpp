#include<iostream>
#define size 100005
using namespace std;
long long int prefix[size]; //구간합 배열
long long int results[size];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		prefix[i] = temp;
		prefix[i] += prefix[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int head, tail;
		scanf("%d %d", &head, &tail); //head 에서 tail까지 합 구해야 함.
		results[i] = prefix[tail] - prefix[head-1];
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld \n", results[i]);
	}
	return 0;
}
