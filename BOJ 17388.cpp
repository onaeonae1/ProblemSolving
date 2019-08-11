#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	vector<int> scores;
	vector<string> university;
	university.push_back("Soongsil");
	university.push_back("Korea");
	university.push_back("Hanyang");
	int count = 0;
	int min = 1000;
	for (int i = 0; i < 3; i++) {
		int value;
		cin >> value;
		count += value;
		scores.push_back(value);
		if (value < min) {
			min = value;
		}
	}
	if (count >= 100) { //합이 백을 넘으므로
		cout << "OK" << endl;
	}
	else {
		for (int i = 0; i < scores.size(); i++) {
			if (scores.at(i) == min) {
				cout << university.at(i) << endl;
			}
		}
	}
	return 0;
}
