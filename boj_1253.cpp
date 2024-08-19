#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	vector<int> items(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &items[i]);
	}
	int ans = 0;
	sort(items.begin(), items.end());
	for (int i = 0; i < N; i++) {
		int target = items[i];
		int left = 0;
		int right = N - 1;
		while (left < right) {
			int sum = items[left] + items[right];
			if (sum == target) {
				if (left != i and right != i) {
          // 나 자신은 답이 될 수 없음
					ans++;
					break;
				}
				else if (left == i) {
					left++;
				}
				else if (right == i) {
					right--;
				}
			}
			else if (sum < target) {
				// 원하는 것보다 적게 뜸? 그러면 l++
				left++;
			}
			else {
				// 원하는 것보다 크게 뜸? 그러면 r--
				right--;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
