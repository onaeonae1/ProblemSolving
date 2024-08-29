#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> minHoles;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	int maxV = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		temp += i;
		maxV = (maxV < temp) ? temp : maxV;
		minHoles.push_back(maxV);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		int t = lower_bound(minHoles.begin(), minHoles.end(), temp) - minHoles.begin();
		t++;
		cout << t << " ";
	}

	return 0;
}
