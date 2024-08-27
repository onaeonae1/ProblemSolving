#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	map < string, double > score_map;
	
	score_map["A+"] = 4.5;
	score_map["A0"] = 4.0;
	score_map["B+"] = 3.5;
	score_map["B0"] = 3.0;
	score_map["C+"] = 2.5;
	score_map["C0"] = 2.0;
	score_map["D+"] = 1.5;
	score_map["D0"] = 1.0;
	score_map["F"] = 0.0;

	int t = 20;
	double scoreSum = 0.0;
	double unitSum = 0.0;
	while (t--) {
		string blah;
		double unit;
		string score;
		cin >> blah >> unit >> score;
		
		if (score != "P") {
			double current = score_map[score];
			scoreSum += (current * unit);
			unitSum += unit;
		}
	}
	double average = scoreSum / unitSum;
	printf("%.6f", average);
	// cout << average << endl;

	return 0;
}
