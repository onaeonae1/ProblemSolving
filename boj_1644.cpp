#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> primes;
vector<int> prefix;
void eratos(int n) {
    vector<bool> prime(n + 1, true);

    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i]) primes.push_back(i);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
	int N;
    cin >> N;
    eratos(N+N);
    int ret = 0;
    int start = 0;
    int end = 0;
    int sum = 0;
    
    while (end < primes.size()) {
        if (sum >= N) {
            // N넘겼는데요 -> 숫자 빼주고 한칸 땡겨줌
            sum -= primes[start];
            start++;
        }
        if (sum < N) {
            // 더 가야겠는데요 -> 숫자 넣어주고 한칸 밀어줌
            sum += primes[end];
            end++;
        }
        if (sum == N) {
            //찾은거 같은데유
            ret++;
        }
    }

    cout << ret;
    return 0;
}
