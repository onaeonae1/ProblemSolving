#include<iostream>
#include<vector>
#include<algorithm>
#define L 100005
#define MAXIMUM 2000000005
using namespace std;
vector<long long int >v;
int n; //입력받을 나무의 수
long long int m; //목표 나무의 수확량
long long int res = 0;
long long int maxima(long long int a, long long int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
int compare(int height) {
	long long int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - height > 0) {
			count += (v[i] - height);
		}
	}
	if (count >= m) { //조건 만족. 오른쪽으로
		return 1;
	}
	else { //왼쪽으로
		return 0;
	}
}
void parametic_search() {
	long long int st = 0;
	long long int ed = v[n-1];
	while (st <= ed) {
		long long int md = (st + ed) / 2;
		if (compare(md) == 1) {
			res = maxima(res, md);
			st = md + 1;
		}
		else if (compare(md) == 0) {
			ed = md - 1;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		long long int temp;
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end()); //오름차순 정렬
	parametic_search();
	printf("%lld \n", res);
	return 0;
}
