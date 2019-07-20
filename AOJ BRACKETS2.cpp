#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int c;
	int results[105] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		stack<char> temp;
		string given;
		cin >> given; //문자열 입력받음
		for (int i = 0; i < given.length(); i++) {
			char now = given[i];
			if (now == '(' || now == '{' || now == '[') { //열리는 괄호
				temp.push(given[i]);
			}
			else { //닫히는 괄호
				if (temp.empty() == false) {
					int value = now + temp.top(); //스택의 top과 현재 들어온 값 더해줌
					if (value == 248 || value == 184 || value == 81) { //아스키 코드로 합 맞음
						temp.pop();
					}
					else { //합이 안맞음
						temp.push(now);
						break;
					}
				}
				else { //처음부터 닫히는 괄호가 들어올 때
					temp.push(now);
					break;
				}
			}
		}
		if (temp.empty() == true) {
			results[index] = 1;
		}
		else {
			results[index] = 0; 
		}
		index++;
	}
	for (int i = 0; i < index; i++) {
		if (results[i] == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
