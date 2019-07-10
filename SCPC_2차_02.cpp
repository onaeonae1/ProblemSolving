#include<iostream>
#include<cstring>
using namespace std;
int DP[5005] = { 0, }; //DP[i] :  1~i 까지 유사도
int DPRotate[5005][5005] = { 0 , }; //DPRotate[i][j] : i 에서 j까지 Rotate 시켰을 때 유사도
int A[5005] = { 0, }; int B[5005] = { 0, };
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int RotateSearch(int start, int end) {
	int value = 0;
	if (start == end) {
		value = (A[start] == B[start]);
		return value;
	}
	else if (end > start + 1) { //한칸 이상 차이 : 점화식 이용 가능
		if (DPRotate[start + 1][end - 1] == -1) { //초기화 안됨 RotateSearch 돌려야
			value += RotateSearch(start + 1, end - 1);
		}
		else {
			value += DPRotate[start + 1][end - 1];
		}
	}
	value += (A[start] == B[end]);
	value += (A[end] == B[start]);
	return value;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int c;
	int results[45] = { 0, };
	int index = 0; 
	cin >> c;
	while (c--) {
		memset(DP, 0, sizeof(DP)); memset(DPRotate, -1, sizeof(DPRotate));
		memset(A, 0, sizeof(A));  memset(B, 0, sizeof(B));
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}
		//1차원 DP 초기화
		for (int i = 0; i < N; i++) {
			if (i > 0) {
				DP[i] = DP[i - 1];
			}
			DP[i] += (A[i] == B[i]);
			
		}
		//rotate 생각해주기
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				if (DPRotate[i][j] == -1) {
					DPRotate[i][j] = RotateSearch(i, j);
				}
				if (i > 0) {
					int temp = (DP[i - 1] + DPRotate[i][j] + DP[N - 1] - DP[j]);
					result = max(result, temp);
				}
			}
		}
		results[index] = result;
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << "Case #" << i + 1 << endl;
		cout << results[i] << endl;
	}
	return 0;
}
