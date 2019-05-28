#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int n; int m;
int compare(int length) {
	int cameras = 0; //설치된 카메라의 수
	int prev_camera = 0; //(방금) 설치된 카메라의 위치
	for (int i = 0; i < m; i++) {
		//0번째 길이는 무조건 가능
		if (i == 0) {
			cameras++;
			prev_camera = v[0];
		}
		else if (v[i] - prev_camera >= length) { //기준 길이 조건에 맞게 카메라 새로 설치 가능.
			cameras++;
			prev_camera = v[i];
		}
	}
	if (cameras >= n) { 
		//카메라를 n보다 더 많이 설치 할 수 있음. 그렇기에 더 긴 길이 범위에서 검색해봐야 함.
		return 1;
	}
	else {
		//카메라를 n만큼 설치 불가. 그렇기에 더 짧은 길이 범위에서 검색해봐야 함.
		return -1;
	}
}
int parametric_search() {
	int start = 0;
	int end = v[m - 1];
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (start == end) { //이진 탐색 종료 조건
			return mid;
		}

		//검색 기준 길이의 범위 조정하기
		if (compare(mid) == -1) {
			end = mid - 1;
		}
		else if (compare(mid) == 1) {
			start = mid + 1;
		}
	}
	return mid;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	float results[55] = { 0, };
	int index = 0;
	int c;
	scanf("%d", &c);
	while(c--) 
	{
		scanf("%d%d", &n, &m);
		v.resize(m);
		for (int i = 0; i < m; i++) {
			float temp;
			scanf("%f", &temp);
			v[i] = temp * 10000;
		}
		results[index] = (parametric_search() / 10000.0);
		index++;
	}
	for (int i = 0; i < index; i++) {
		printf("%.2f \n", results[i]);
	}
	return 0;
}
