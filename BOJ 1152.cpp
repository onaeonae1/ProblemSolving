#include<iostream>
#include<string>
using namespace std;
int main() {
	string message;
	getline(cin, message); //공백 포함 입력
	int count = 1;
	int startindex = 0;
	int endindex = message.size();
	if (message.at(0) == ' ') { //공백이 맨처음에 들어옴
		startindex++;
		if (message.size() == 1) { //공백 하나밖에 존재X
			cout << 0 << endl;
			return 0;
		}
	}
	if (message.back() == ' ') { //끝에 공백 붙음
		endindex--;
	}
	for (int i = startindex; i <endindex; i++) {
		if (message.at(i) == ' ') {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
