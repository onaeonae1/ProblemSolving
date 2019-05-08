#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int search(deque<int>& A) {
	int ans = 0;
	while (A.size() >= 2) { //합칠 것이 남아 있을 때
		sort(A.begin(), A.end()); //오름차순으로 정렬해주고
		//앞의 2개(가장 작은 것 2개)를 꺼내준다.
		int alpha = A.front();
		A.pop_front();
		int beta = A.front();
		A.pop_front();
		//이를 전체 합에 더해주고
		int sum = alpha + beta;
		ans += sum;
		//앞에 그 결과를 추가!
		A.push_front(sum);
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
		int n;
		cin >> n;
		deque<int> A;
		for (int i = 1; i <= n; i++) {
			int v;
			cin >> v;
			A.push_back(v);
		}
		sort(A.begin(), A.end()); //오름차순으로 정렬해줌.
		results[index] = search(A);
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
