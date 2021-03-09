#include<iostream>
#include<algorithm>
#include<vector>
#define L 1000005
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector <pair<int, int> >lines;
	int N;
	cin >> N;
	lines.resize(N, make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		cin >> lines[i].first >> lines[i].second;
	}
	sort(lines.begin(), lines.end());
	int from, to;
	long long int total = 0;

	// init
	from = lines[0].first; //끊기지 않는 한 최소-> 시작지점
	to = lines[0].second; //끊기지 않는 한 최대 -> 종료지점
	for (int i = 1; i < N; i++) {
		if (lines[i].first < to) { // 시작 지점이 범위 내에 포함
			if (lines[i].second > to) {
				to = lines[i].second;
			}
		}
		else { //범위 초과 -> 길이 계산 후 from 변경 필요
			total += abs(from - to);
			from = lines[i].first;
			to = lines[i].second;
		}
	}
	total += abs(from - to);
	cout << total << endl;
	return 0;
}
