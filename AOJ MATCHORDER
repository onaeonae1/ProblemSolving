#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int search(deque<int>& R, deque<int>& K) {
	int ans = 0;
	while (K.empty() == false && R.empty() == false) {
		if (K.front() < R.front()) { //이번 선수는 절대 이길 수 없음.
			//따라서 가장 강력한 선수와 매칭 시킨다.
			K.pop_front();
			R.pop_back();
		}
		else { //이번 선수는 이기는 경우의 수가 있음.
			ans++;
      //front의 선수들끼리 매칭시킨다.
			//정렬을 했으므로 이 경우가 가장 차이가 적게(=효율적으로) 매칭시키는 경우이다.
			K.pop_front();
			R.pop_front();
		}
	}
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	int c; 
	cin >> c;
	int index = 0;
	int results[55] = { 0, };
	while (c--) {
		deque<int> Rus; //러시아팀 
		deque<int> Kor; //한국팀
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int v;
			cin >> v;
			Rus.push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			int v;
			cin >> v;
			Kor.push_back(v);
		}
		sort(Rus.begin(), Rus.end()); //오름차순 정렬
		sort(Kor.begin(), Kor.end()); //오름차순 정렬
		results[index] = search(Rus, Kor);
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
