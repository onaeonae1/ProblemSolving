#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int N;
long long int arr[10005];
int main() {
	scanf("%d", &N);
	long long int max = -1;
	for (int i = 1; i <=N; i++) {
		scanf("%lld", &arr[i]);
		max = (max < arr[i]) ? arr[i] : max;
	}
	sort(arr+1, arr + N+1);


	// 최소로 가능한 경우
	// N이 홀수 인 경우 -> 1 2 5 6 10
	// 두개를 합해서 처리하는게 더 싸게 먹히는 경우가 있을까?
	// 되도록이면 2개를 사용해야 한다

	// 마지막에 무조건 하나만 남는 경우

	int tempN = N;;
	if (N % 2 == 1) {
		max = arr[N];
		tempN = N - 1;
	}
	else {
		max = 0;
	}
	for (int i = 1; i <= (tempN) / 2; i++) {
		long long int head = arr[i];
		long long int tail = arr[tempN - i + 1];
		long long int temp = (head)+tail;
		max = (temp < max) ? max : temp;
	}
	printf("%lld", max);
	return 0;
}
