#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    // int 형을 vector<int> 컨테이너에 담는, 자식은 나보다 큼을 보장하는, 최소힙
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N * N; i++) {
        int num;
        scanf("%d", &num);
        minHeap.push(num);
        if (minHeap.size() > N) {
            minHeap.pop();
        }
    }

    cout << minHeap.top() << endl;

    return 0;
}
