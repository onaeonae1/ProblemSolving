#include<iostream>
#include<vector>
using namespace std;
int main() {
	double list[10] = { 350.34, 230.90, 190.55, 125.30, 180.90 ,};
	vector<double> ans;
	int c;
	scanf("%d", &c);
	while (c--) {
		double sum = 0;
		for (int i = 0; i < 5; i++) {
			double temp;
			cin >> temp;
			sum += temp * list[i];
		}
		ans.push_back(sum);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("$%.2lf\n", ans.at(i));
	}
	return 0;
}
