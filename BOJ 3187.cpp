#include<iostream>
#include<cstring>
#define L 255
using namespace std;
char map[L][L]; //맵 배열
bool visit[L][L]; //체크 배열
int r, c;
int lSheep, lWolf; //지역 양, 지역 늑대
int tSheep, tWolf; //전체 양, 전체 늑대
bool inFence; //울타리 안에 있는지
void engine(int y , int x) {
	visit[y][x] = true;
	if (map[y][x] == 'k') {
		lSheep++;
	}
	if (map[y][x] == 'v') {
		lWolf++;
	}
	//4방향 탐색
	if (map[y][x + 1] != '#' && visit[y][x + 1] == false) {
		engine(y, x + 1);
	}
	if (map[y][x - 1] != '#' && visit[y][x - 1] == false) {
		engine(y, x - 1);
	}
	if (map[y+1][x] != '#' && visit[y+1][x] == false) {
		engine(y+1, x);
	}
	if (map[y-1][x] != '#' && visit[y-1][x] == false) {
		engine(y-1, x);
	}
}
int main() {
	memset(map, '#', sizeof(map)); //일단 다 울타리로 초기화
	cin >> r >> c;
	for (int i = 1; i <= r; i++) { //행 
		for (int j = 1; j <= c; j++) { //열
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] != '#' && visit[i][j] != true) { //울타리 X, 방문 X
				engine(i, j); //검색 시작
				//양과 늑대 처리해줌
				if (lSheep > lWolf) { //양생존
					tSheep += lSheep;
				}
				else { //늑대 생존
					tWolf += lWolf;
				}
				lSheep = 0;
				lWolf = 0;
			}
		}
	}
	cout << tSheep << " " << tWolf << endl;
	return 0;
}
