#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int buySingle(vector<int> & P, int M) {
	//Q1 : 한번 선택했을 때 가능한 주문방법 구하기 : 구해준 결과 바탕으로 nC2 조합
	int result = 0;
	vector<long long> count(M, 0);
	for (int i = 0; i < P.size(); i++) {
		count[P[i]]++;
	}
	for (int i = 0; i < M; i++) {
		if (count[i] >= 2) {
			result += (count[i] * (count[i] - 1)) / 2 % 20091101;
		}
	}
	return result;
}
int buyMulti(vector<int>& P, int M) {
	//Q2 : 여러번 선택했을 때 가능한 주문방법의 최대 
	vector<int> DP(P.size(), 0); //1~i까지 고려했을때 최대 구매횟수
	vector<int> prev(M, -1); //P[] 가 S였던 마지막 자리
	for (int i = 0; i < P.size(); i++) {
		if (i > 0) {
			DP[i] = DP[i - 1];
		}
		else {
			DP[i] = 0;
		}
		int now = prev[P[i]];
		if (now != -1) {
			DP[i] = max(DP[i], DP[now] + 1);
		}
		prev[P[i]] = i;
	}
	return DP.back();

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int c;
	int results[55][2] = { 0, };
	int index = 0;
	cin >> c;
	while (c--) {
		int N, M; //박스 수 , 분배 수
		vector<int> P; //MOD 결과를 저장
		P.push_back(0);
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) { //각종 배열 초기화
			int value;
			cin >> value; 
			P.push_back((P.back() + value) % M);
		}
		results[index][0] = buySingle(P, M);
		results[index][1] = buyMulti(P, M);
		index++;
	}
	for (int i = 0; i < index; i++) {
		printf("%d %d\n", results[i][0], results[i][1]);
	}
	return 0;
}
