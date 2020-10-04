#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		char s[105];
		vector<char> stack;
		bool result = true;
		scanf("%[^\n]%*c", &s);
		if (s[0] == '.') { //종료조건 판단
			break;
		}
		//반복하면서 스택 채우기
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '(' || s[i] == '[') {
				stack.push_back(s[i]);
			}
			//
			if (s[i] == ')') {
				if (stack.empty()) { //잘못 등장함
					result = false;
					break;
				}
				else {
					if (stack.back() == '(') {
						stack.pop_back();
					}
					else {
						result = false;
						break;
					}
				}
			}
			if (s[i] == ']') {
				if (stack.empty()) { //잘못 등장함
					result = false;
					break;
				}
				else {
					if (stack.back() == '[') {
						stack.pop_back();
					}
					else {
						result = false;
						break;
					}
				}
			}
		}
		//결과 출력
		if (stack.empty() && result) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	return 0;
}
