#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct guitar {
	string name;
	int sum=0;
	int length;
};
bool compare(const guitar &a, const guitar &b) {
	if (a.length == b.length) {
		if (a.sum == b.sum) {
			return a.name < b.name;
		}
		else {
			return a.sum < b.sum;
		}
	}
	return a.length < b.length;
}
int main() {
	vector<guitar> G;
	int n;
	cin >> n;
	//입력 모두 받기
	for (int i = 0; i < n; i++) {
		string element;
		int sum=0;
		cin >> element;
		for (int j = 0; j < element.size(); j++) {
			if (element.at(j) >= '0' && element.at(j) <= '9') {
				sum += element.at(j) - '0';
			}
		}
		guitar temp;
		temp.name = element;
		temp.sum = sum;
		temp.length = element.size();
		G.push_back(temp);
	}
	sort(G.begin(), G.end(), compare);
	for (int i = 0; i < G.size(); i++) {
		cout << G[i].name << endl;
	}
	return 0;
}
