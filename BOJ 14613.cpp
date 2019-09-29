#include<iostream>
using namespace std;
int main() {
	double DP[25][45] = { 0, };
	double ranks[10] = { 0, }; //0~4 브론즈~다이아
	double wp, lp, dp; //승, 패, 무 확률
	scanf("%lf %lf %lf", &wp, &lp, &dp);
	DP[0][20] = 1;
	for (int i = 1; i <= 20; i++) {
		for (int j = 0; j <= 40; j++) {
			double& now = DP[i][j]; //현재 판
			double& lose = DP[i - 1][j-1]; //전판에 짐
			double& win = DP[i - 1][j + 1]; //전판에 이김
			double& draw = DP[i - 1][j]; //전판에 비김
			if (j == 0) {
				now = win * lp;
			}
			else if (j == 40) {
				now = lose * wp;
			}
			else { //졌다 이김, 비겼다 비김, 이겼다 짐 
				now = win * lp;
				now += draw * dp;
				now += lose * wp;
			}
		}
	}
	int rank = 0; //0~4
	for (int i = 0; i < 40; i+=10) { //ranks에 확률 넣기
		for (int j = i; j < i + 10; j++) {
			ranks[rank] += DP[20][j];
		}
		rank++;
	}
	ranks[rank++] = DP[20][40];
	for (int i = 0; i < rank; i++) {
		printf("%.8lf \n", ranks[i]);
	}
	return 0;
}
