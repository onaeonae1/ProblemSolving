#include<iostream>
#include<vector>
#include<string>
#define CLK true //시계
#define CTR false //반시계
using namespace std;
vector<int> getPi(string name) { //pi 배열 구해줌
	int m = name.size();
	int j = 0;
	vector<int> pi(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		while (j > 0 && (name[i] != name[j])) {
			j = pi[j - 1];
		}
		if (name[i] == name[j]) {
			j++;
			pi[i] = j;
		}
	}
	return pi;
}
int getRes(string A, string key) { //A에서 key에 대해 탐색
	vector<int> pi = getPi(key);
	int i = 0; //next에 대해
	int j = 0; //now에 대해
	while (i <= A.size() - key.size()) {
		if (j < key.size() && A[i + j] == key[j]) {
			j++;
			if (j == key.size()) { //완전 일치
				return i; //찾았음을 표시
			}
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				i += (j - pi[j - 1]);
				j = pi[j - 1];
			}
		}
	}
	return 0;
}
int main() {
	int c;
	int results[55] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		string now;  //현재 상태
		string next; //맞춰야 할 다음 상태
		bool status = true; //이동 방향 기억
		int n;
		int count = 0; //이동 횟수 저장
		cin >> n;
		cin >> now; //처음 상태 입력받음
		for (int i = 0; i < n; i++) {
			cin >> next; 
			if (status == CLK) { //시계
				string temp = next + next;
				count += getRes(temp, now); //그대로 탐색
			}
			else {
				string temp = now + now;
				count += getRes(temp, next); //반대로 탐색
			}
			now = next;
			status = !status; //방향을 반대로 전환시켜줌
		}
		results[index] = count;
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
