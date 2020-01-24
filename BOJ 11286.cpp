#include<iostream>
#include<queue>
using namespace std;
struct num {
	int value;
};
struct cmp { //절대값을 비교하기 위해 비교 연산자를 만들어 사용
	bool operator()(num alpha, num beta) {
		int a = abs(alpha.value);
		int b = abs(beta.value);
		if (a == b) {
			return alpha.value > beta.value;
		}
		else {
			return a > b;
		}
	}
};
int main() {
	priority_queue<num, vector<num>,cmp> pq; //비교 연산자 생략하여 선언 : 최대 힙으로 설정됨
	int c;
	scanf("%d", &c);
	while (c--) {
		int val;
		scanf("%d", &val);
		if (val == 0) { //출력 명령
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				int element = pq.top().value;
				printf("%d\n", pq.top().value);
				pq.pop();
			}
		}
		else {
			struct num temp;
			temp.value = val;
			pq.push(temp);
		}
	}
	return 0;
}
