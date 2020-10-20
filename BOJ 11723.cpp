#include<iostream>
#include<string>
#include<vector>
using namespace std;
int S = 0;
int main() {
	//20자리 비트 연산
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int value;
		if (s == "add") { //add x 
			cin >> value;
			S = S | (1 << value);
		}
		if (s == "remove") { //remove x 
			cin >> value;
			S = S & ~(1 << value);
		}
		if (s == "check") { //check x 
			cin >> value;
			if (S&(1 << value)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if (s == "toggle") { //toggle
			cin >> value;
			S = S ^ (1 << value);
		}
		if (s == "all") { //all
			S = (1 << 21) - 1; //0xFFFFF
		}
		if (s == "empty") { //empty
			S = 0;
		}
	}
	return 0;
}
