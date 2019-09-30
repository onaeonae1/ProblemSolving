#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string> messages;
	while (true) {
		string message; //수정해서 들어갈 문자열
		string temp; //임시로 받는 문자열
		getline(cin, temp);
		if (temp == "END") { //종료 명령
			break;
		}
		else {
			while (temp.empty() == false) { //역순으로 집어넣기
				message.push_back(temp.back());
				temp.pop_back();
			}
			messages.push_back(message);
		}
	}
	for (int i = 0; i < messages.size(); i++) {
		cout << messages.at(i) << endl;
	}
	return 0;
}
