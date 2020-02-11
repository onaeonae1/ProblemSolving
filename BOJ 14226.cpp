#include<iostream>
#include<deque>
#define L 2000
using namespace std;
bool check[L][L]; //방문 체크
int target;
int search() {
	deque<pair< pair<int, int>, int>> v;
	v.push_back(make_pair(make_pair(1, 0), 0)); //초기 상태
	//v.first = (현재 이모티콘, 클립보드 이모티콘)
	//v.second = 진행 횟수
	while (v.size()>0) {
		//처리할 명령
		pair<pair<int, int>, int> q = v.front();
		int nowEmo = q.first.first;
		int boardEmo = q.first.second;
		int steps = q.second;
		//명령을 뽑아냈으므로 제거해줌
		v.pop_front();
		if (nowEmo == target) { //종료
			return steps;
		}
		if (nowEmo > 0 && nowEmo < L) {
			//복사 조건
			if (check[nowEmo][nowEmo] == false) { 
				check[nowEmo][nowEmo] = true; //방문체크
				v.push_back(make_pair(make_pair(nowEmo, nowEmo),steps+1)); //복사
			}
			//감소 조건
			if (check[nowEmo - 1][boardEmo] == false) {
				check[nowEmo - 1][boardEmo] = true; //방문체크
				v.push_back(make_pair(make_pair(nowEmo-1, boardEmo), steps+1)); //감소
			}
		}
		//붙여넣기 조건
		if (boardEmo > 0 && nowEmo + boardEmo < L) {
			if (check[nowEmo + boardEmo][boardEmo] == false) {
				check[nowEmo + boardEmo][boardEmo] = true; //방문 체크
				v.push_back(make_pair(make_pair(nowEmo + boardEmo, boardEmo), steps + 1));
			}
		}
	}
}
int main() {
	cin >> target;
	int result = search();
	cout << result << endl;
	return 0;
}
