#include<iostream>
#include<math.h>
using namespace std;
int N;
int board[3000][3000]; //종이들의 모음
int counts[5]; //종이 갯수 배열 0 : -1, 1 : 0, 2: 1
bool check(int sty, int stx, int length) { //같은 종이로 이루어져 있는지 & 종이 갯수 추가
	bool ret = true;
	int expected = length * length;
	int edy = sty + length; int edx = stx + length;
	int first = board[sty][stx];
	//검색
	for(int i=sty; i<edy; i++){
		for (int j = stx; j < edx; j++) {
			if (board[i][j] != first) {
				ret = false;
				break;
			}
		}
	}
	if (ret != false) {
		counts[first + 1]++;
	}
	return ret;
}
bool div(int sty, int stx, int length) {
	bool selfCheck = check(sty, stx, length); //자신검사
	if (selfCheck == true) { //크기가 1이라면 아마 같은 값이 나올것이므로, 1 예외처리 X
		return selfCheck;
	}
	else { //9등분
		int m = length / 3;
		bool aa = div(sty, stx, m);
		bool ab = div(sty, stx+m, m);
		bool ac = div(sty, stx+m+m, m);
		bool ba = div(sty+m, stx, m);
		bool bb = div(sty+m, stx+m, m);
		bool bc = div(sty+m, stx+m+m, m);
		bool ca = div(sty+m+m, stx, m);
		bool cb = div(sty+m+m, stx+m, m);
		bool cc = div(sty+m+m, stx+m+m, m);
	}
	return selfCheck;
}
int main() {
	//입력 && 부분합 구하기
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	div(1, 1, N);
	printf("%d\n", counts[0]);
	printf("%d\n", counts[1]);
	printf("%d\n", counts[2]);
	return 0;
}
