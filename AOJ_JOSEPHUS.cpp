#include<iostream>
#include<list>
using namespace std;
void process(list<int>& people, int K) {
	list<int>::iterator now=people.begin();
	while (people.size() > 2) {
		now = people.erase(now);
		if (now == people.end()) {
			now = people.begin();
		}
		for (int i = 0; i < K-1; i++) {
			now++;
			if (now == people.end()) {
				now = people.begin();
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int c;
	int results[55][2] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		int N, K;
		cin >> N >> K;
		list<int> people;
		for (int i = 0; i < N; i++) {
			people.push_back(i + 1);
		}
		process(people, K);
		results[index][0] = people.front();
		results[index][1] = people.back();
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i][0] << " " << results[i][1]<<endl;
	}
	return 0;
}
