#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string message;
	cin >> message;
	sort(message.begin(), message.end());
	while (!message.empty()) {
		cout << message.back();
		message.pop_back();
	}
	return 0;
}
