#include<iostream>
#include<vector>
#define MAX 100000000 //한 레슨의 최대 범위
using namespace std;
vector<int> v;
int N; int M;
int minimum(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}
int compare(int length) {
	int local_sum = 0;
	int count = 1;
	for (int i = 0; i < v.size(); i++) {
		//기준 길이를 초과하면
		if (local_sum + v[i] > length) {
			//일부 예외를 제외하고는,
			if (v[i] > length) {
				return 0;
			}
			//블루레이 한 편 새로 찍는다!
			local_sum = v[i];
			count++;
		}
		//초과하지 않는다면
		else {
			//계속 이어 가면 된다.
			local_sum += v[i];
		}
	}
	//블루레이 몇 개 찍었는지 확인해보기
	if (M>=count) { 
		return 1; 
	}
	else { 
		return 0;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	v.resize(N);
	for (int i = 0; i < N; i++) { //N개의 lesson 입력받기
		scanf("%d", &v[i]);
	}
	int left = v[N-1]; 
	int right = MAX;
	int min = MAX;
	while (left <= right) {
		int mid = (left + right) / 2;
		int flag = compare(mid); //이거로 left, right의 향방을 결정
		if (flag == 1) {
			min = minimum(min, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d", min);
	return 0;
}
