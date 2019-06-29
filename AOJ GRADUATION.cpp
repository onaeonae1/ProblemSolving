#include<iostream>
#include<intrin.h> //bitcount (__popcnt(int num)) 사용하려고 -> gcc/g++ 에서는 안됨!
#include<cstring>
using namespace std;
int N, K, M, L; 
const int INF = 99999999;
int PreSet[15]; int SemSet[15]; int cache[10][1 << 13];
int min(int a, int b) { return a < b ? a : b; }
unsigned int bitcount(int n) {
	return __popcnt(n);
}
int graduate(int semester, int taken) {
	if (bitcount(taken) >= K) {
		return 0;
	}
	if (semester == M) {
		return INF;
	}
	int & ret = cache[semester][taken];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	int canTake = (SemSet[semester] & ~taken);
	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & PreSet[i]) != PreSet[i]) {
			canTake &= ~(1 << i);
		}
	}
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitcount(take) > L) {
			continue; 
		}
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	int c;
	int results[55];
	int index = 0;
	cin >> c;
	while (c--) {
		//배열초기화
		memset(cache, -1, sizeof(cache)); memset(PreSet, 0, sizeof(PreSet)); memset(SemSet, 0, sizeof(SemSet));
		//입력 데이터 처리 과정
		cin >> N >> K >> M >> L;
		//과목별 선수과목 입력
		for (int i = 0; i < N; i++) {
			int v; //i 번째 과목의 선수 과목의 갯수
			cin >> v;
			for (int j = 0; j < v; j++) {
				int temp;
				cin >> temp;
				PreSet[i] |= (1 << temp); //시프트 연산으로 해당 자리 채워줌
			}
		}
		//학기별 개설과목 입력
		for (int i = 0; i < M; i++) {
			int v;
			cin >> v;
			for (int j = 0; j < v; j++) {
				int temp;
				cin >> temp;
				SemSet[i] |= (1 << temp);
			}
		}
		int result = graduate(0, 0);
		results[index] = result;
		index++;
	}
	for (int i = 0; i < index; i++) {
		if (results[i] == INF) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << results[i] << endl;
		}
	}
	return 0;
}
