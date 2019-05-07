#include<iostream>
#define L 105
using namespace std;
int map[L][L]; //사용할 맵.
int N;
int stx[25];
int sty[25];
int maxgen[25];
//이동 명령을 저장
//op[a][b] : a번 드래곤 커브의 b번째 세대의 이동 명령.
struct abc {
	int gen;
	int length;
	int move[1050]; 
}op[25][105];
void function(int curve) { //현재 보고 있는 드래곤 커브를 세대에 맞춰서 진행.
	for (int i = 1; i <= maxgen[curve]; i++) { //현재 조작할 세대
		//현재 조작할 세대의 길이
		int count = 0;
		for (int j = i - 1; j >= 0; j--) { //가장 가까운 세대 순으로 과거 명령 참조
			//과거 명령의 길이
			int prevlength = op[curve][j].length ; 
			for (int k = prevlength; k >= 1; k--) { //참조중인 세대의 명령을 역순으로 참조.
				count++;
				int prevop = op[curve][j].move[k];
				prevop = (prevop + 1)%4;
				op[curve][i].move[count] = prevop;
			}
		}
		op[curve][i].gen = i;
		op[curve][i].length = count;
	}
}
void simulate(int curve) {
	int x = stx[curve];
	int y = sty[curve];
	map[x][y] = 1; //맵에 방문 표시
	for (int i = 0; i <= maxgen[curve]; i++) { //전체 세대 결과에 대해
		for (int j = 1; j <= op[curve][i].length; j++) { //참조 중인 세대의 길이만큼
			//해당 세대의 명령어를 참조 한다.
			if (op[curve][i].move[j] == 0) {
				x++;
			}
			if (op[curve][i].move[j] == 1) {
				y--;
			}
			if (op[curve][i].move[j] == 2) {
				x--;
			}
			if (op[curve][i].move[j] == 3) {
				y++;
			}
			map[x][y] = 1; //맵에 방문 표시
		}
	}
}
int check() {
	int ans = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			int nowx = i;
			int nowy = j;
			//정사각형 체크(길이1)
			if (map[nowx][nowy] == 1 && map[nowx + 1][nowy] == 1 && map[nowx][nowy + 1] == 1 && map[nowx + 1][nowy + 1]) {
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	//등장하는 드래곤 커브의 갯수 입력받음
	cin >> N; 
	for (int i = 1; i <= N; i++) {
		//N개의 커브에 대해 시작 (x,y,d,g) 입력받기
		//시작x , 시작y, 시작 방향, 전체세대
		cin >> stx[i] >> sty[i] >> op[i][0].move[1]>>maxgen[i]; 
		op[i][0].gen = 0; //처음 세대는 0세대.
		op[i][0].length = 1; //처음에는 하나의 명령어만 가짐.
	}
	for (int i = 1; i <= N; i++) {
		function(i);
		simulate(i);
	}
	int result = check();
	cout << result << endl;
	return 0;
}
