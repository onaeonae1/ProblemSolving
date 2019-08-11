#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	string res;
	cin >> n;
	cin >> res;
	int count = 0; 
	int bonus = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res.at(i) == 'O') {
			count += (i+1 + bonus);
			bonus++;
		}
		if (res.at(i) == 'X') {
			bonus = 0;
		}
	}
	cout << count << endl;
	return 0;
}
