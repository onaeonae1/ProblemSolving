#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main() {
	int wideth, height, n;
	int temp1, temp2;
	int sum = 0;
	//내 정보
	int direc;
	int dist;
	vector<pair<int, int>> targets; //목표
	cin >> wideth;
	cin >> height;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> alpha;
		cin >> alpha.first;
		cin >> alpha.second;
		targets.push_back(alpha);
	}
	cin >> direc >> dist;
	if (direc == 1) {
		temp1 = dist;
	}
	else if (direc == 2) {
		temp1 = wideth * 2 + height- dist;
	}
	else if (direc == 3) {
		temp1 = wideth * 2 + height * 2 - dist;
	}
	else if (direc == 4) {
		temp1 = wideth + dist;
	}
	for (int i = 0; i < n; i++) {
		if (targets[i].first == 1) {
			temp2 = targets[i].second;
		}
		else if (targets[i].first == 2) {
			temp2 = wideth * 2 + height - targets[i].second;
		}
		else if (targets[i].first == 3) {
			temp2 = wideth * 2 + height * 2 - targets[i].second;
		}
		else if (targets[i].first == 4) {
			temp2 = wideth + targets[i].second;
		}
		int l1 = abs(temp1 - temp2);
		int l2 = 2 * wideth + 2 * height - l1;
		if (l1 > l2) {
			sum += l2;
		}
		else {
			sum += l1; 
		}
	}
	cout << sum << endl;
	return 0;
}
