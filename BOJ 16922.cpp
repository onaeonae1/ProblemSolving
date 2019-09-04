#include<iostream>
#include<vector>
#define M 1005
using namespace std;
int N;
int answers;
bool check[M]; //중복 숫자 체크
vector<int> roman;
//DFS로 중복조합 구현하기
void search(int now, int take, int number) {
	//취한 로마 숫자의 수, 취하는 로마숫자 번호, 10진수 값
	if (now == N) { //N만큼의 로마숫자 쓰임
		if (check[number] == false) {
			check[number] = true; //방문 표시
			answers++; //정답 추가
		}
		return;
	}
	for (int romenumber = take; romenumber < 4; romenumber++) {
		search(now + 1, romenumber, number + roman.at(romenumber));
	}
}
int main() {
	roman.push_back(1); roman.push_back(5); roman.push_back(10); roman.push_back(50); //I V X L
	cin >> N;
	search(0, 0, 0);
	cout << answers << endl;
	return 0;
}
