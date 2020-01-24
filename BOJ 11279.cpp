#include<iostream>
#include<queue>
using namespace std;
int main() {
	priority_queue<int, vector<int>> pq; //비교 연산자 생략하여 선언 : 최대 힙으로 설정됨
	int c;
	scanf("%d", &c);
	while (c--) {
		int num;
		scanf("%d", &num);
		if (num == 0) { //출력 명령
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			int temp = num;
			pq.push(temp);
			//음수로 사용하는 이유
			//STL에서의 우선순위 큐는 최대힙이므로
			//음수로 값 넣어주면 최소힙처럼 쓸 수 있음
		}
	}
	return 0;
}
