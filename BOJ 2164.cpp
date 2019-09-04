#include<iostream>
#include<deque>
using namespace std;
int main() {
	int n;
	cin >> n;
	deque<int> cards;
	for (int i = 1; i <= n; i++) {
		cards.push_back(i);
	}
	while (cards.size() >= 2) {
		cards.pop_front(); //가장 앞에 있는 카드를 버림
		int element = cards.front(); // 그 다음 카드
		cards.pop_front(); //뽑고
		cards.push_back(element);
	}
	int answer = cards.back();
	cout << answer << endl;
	return 0;
}
