#include<iostream>
#include<list>
#include<vector>
using namespace std;
vector<int> process(list<int>& people, int K) {
	vector<int> ret;
	list<int>::iterator now = people.begin();
	while (people.size() > 0) {
		if (now == people.end()) {
			now = people.begin();
		}
		for (int i = 0; i < K - 1; i++) {
			now++;
			if (now == people.end()) {
				now = people.begin();
			}
		}
		ret.push_back(*now); //제거한 사람 넣어주고
		now = people.erase(now); //iterator 이동
	}
	return ret;
}
int main() {
	int N, K;
	cin >> N >> K;
	list<int> people;
	for (int i = 0; i < N; i++) {
		people.push_back(i + 1);
	}
	vector<int> ret = process(people, K);
	cout << "<";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i);
		if (i < ret.size() - 1) {
			cout << ", ";
		}
	}
	cout << ">" << endl;
	return 0;
}
