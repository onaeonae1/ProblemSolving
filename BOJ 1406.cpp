#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<char> Ldeq; //왼쪽
deque<char> Rdeq; //오른쪽
void controller(char instruction) {
	if (instruction == 'L') { //커서 왼쪽 이동
		if (Ldeq.size() > 0) {
			Rdeq.push_front(Ldeq.back());
			Ldeq.pop_back();
		}
	}
	if (instruction == 'D') { //커서 오른쪽으로 이동
		if (Rdeq.size() > 0) {
			Ldeq.push_back(Rdeq.front());
			Rdeq.pop_front();
		}
	}
	if (instruction == 'B') { //커서 왼쪽 삭제
		if (Ldeq.size() > 0) {
			Ldeq.pop_back();
		}
	}
	if (instruction == 'P') { //추가로 입력받고 왼쪽에 추가
		char detail;
		cin >> detail;
		Ldeq.push_back(detail);
	}
}
int main() {
	string message; //문자열
	int n;
	cin >> message; //문자열 입력받고
	cin >> n; //명령어 길이 입력받고
	//초기에 커서는 가장 오른쪽에 있으므로 왼쪽에 다 넣어줌
	for (int i = 0; i < message.size(); i++) {
		Ldeq.push_back(message.at(i));
	}
	while (n--) {
		char instruction;
		cin >> instruction;
		controller(instruction);
	}
	string result;
	for (int i = 0; i < Ldeq.size(); i++) {
		result.push_back(Ldeq.at(i));
	}
	for (int i = 0; i < Rdeq.size(); i++) {
		result.push_back(Rdeq.at(i));
	}
	cout << result << endl;
	return 0;
}
