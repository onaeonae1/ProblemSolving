#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool compare(char a, char b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(true);
	cin.tie(0);
	string message;
	cin >> message;
	string result = "-1";
	int sum = 0;
	int zerocount = 0;
	//유효성 계산
	for (int i = 0; i < message.size(); i++) {
		char& now = message.at(i);
		if (now - '0' == 0) {
			zerocount++;
		}
		sum += now - '0';
	}
	//0이 하나 이상 있으며, 30의 배수임이 자명함
	if (sum != 0 && sum % 3 == 0 && zerocount >= 1) {
		sort(message.begin(), message.end(), compare); //head, tail 고정됨
		result = message;
	}
	cout << result << endl;
	return 0;
}
