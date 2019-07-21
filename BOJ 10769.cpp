#include<iostream>
#include<string>
using namespace std;
string process(string message) {
	string result="none";
	int Hindex = 0; int Hcount = 0;
	int Sindex = 0; int Scount = 0;
	while (Hindex != message.npos) {
		Hindex = message.find(":-)", Hindex);
		if (Hindex != message.npos) {
			Hcount++;
			Hindex += 3; //중복 탐색을 피하기 위해 이모티콘 길이만큼 이동
		}
	}
	while (Sindex != message.npos) {
		Sindex = message.find(":-(", Sindex);
		if (Sindex != message.npos) {
			Scount++;
			Sindex += 3; //중복 탐색을 피하기 위해 이모티콘 길이만큼 이동
		}
	}
	if (Hcount == 0 && Scount == 0) {
		result = "none";
	}
	else {
		if (Hcount == Scount) {
			result = "unsure";
		}
		else {
			if (Hcount > Scount) {
				result = "happy";
			}
			else {
				result = "sad";
			}
		}
	}
	return result;
}
int main() {
	string message;
	getline(cin, message);
	cout<<process(message);
	return 0;
}
