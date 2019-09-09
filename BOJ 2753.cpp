#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int year;
	bool status = false;
	cin >> year;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) { //윤년
				status = true;
			}
			else {
				status = false;
			}
		}
		else {
			status = true;
		}
	}
	cout << (int)status << endl;
	return 0;
}
