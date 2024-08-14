#include<iostream>
#include<string>
#include<stack>
using namespace std;
void solve(string inputStr) {

}
int main() {
	string raw;
	string ret = "";
	stack<char> rev;

	bool inTag = false;
	getline(cin, raw);
	for (char item : raw) {
		if (item == '<') {
			while (!rev.empty()) {
				char target = rev.top();
				rev.pop();
				ret.push_back(target);
			}
			inTag = true;

		}
		if (inTag) {
			if (item == '>') {
				inTag = false;
			}
			ret.push_back(item);
		}
		else if(item!='>') {
			if (item != ' ') {
				rev.push(item);
			}
			else {
				while (!rev.empty()) {
					char target = rev.top();
					rev.pop();
					ret.push_back(target);
				}
				ret.push_back(' ');
			}
		}
	}
	while (!rev.empty()) {
		char target = rev.top();
		rev.pop();
		ret.push_back(target);
	}
	cout << ret << endl;
	return 0;
}
