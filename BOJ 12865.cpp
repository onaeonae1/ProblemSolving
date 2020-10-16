#include<iostream>
#include<algorithm>
#include<cstring>
#define N 105
#define K 100005
using namespace std;
struct item {
	int value; //가치
	int weight;//무게 
}items[N];
bool compare(const item &a, const item &b) {
	//weight 순 정렬
	return a.weight < b.weight;
}
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}
int DP[K];
int temp[K]; 
int main() {
	int n, k;
	int ret = 0;
	int outlier = 0; //초과값 찾기 위함
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) { //데이터 입력
		int w, v; 
		scanf("%d %d", &w, &v);
		if (w <= k) { //얘네들만 계산에 사용할 수 있다.
			items[i].weight = w;
			items[i].value = v;
			//DP[w] = max(DP[w], v); //가치 초기화
			//ret = max(ret, DP[w]);
		}
		else { //배낭을 초과하는 경우 존재
			outlier++;
		}
	}
	n = n - outlier; //사용가능한 물건들 갯수 수정
	sort(items + 0, items + n + 0, compare); //w 순 정렬
	for (int i = 0; i < n; i++) {
		int w = items[i].weight;
		int v = items[i].value;
		for (int j = 0; j <=k; j++) {
			if (j - w >= 0) {
				temp[j] = max(DP[j], DP[j - w] + v); //같은 물건 중복 사용 방지
			}
		}
		for (int j = 0; j <= k; j++) {
			DP[j] = max(DP[j], temp[j]);
			ret = max(DP[j], ret);
		}
		memset(temp, 0, sizeof(temp));
	}
	printf("%d", ret);
	return 0;
}
