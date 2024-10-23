#include <iostream>
using namespace std;
long long prefix[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    long long ret = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        long long t;
        cin >> t;
        prefix[i] += prefix[i - 1] + t;
    }
    for (int i = 1; i < N - 1; i++) {
        long long now = prefix[i];
        long long start = i + 1;
        long long end = N - 1;
        long long mid;
        long long Idx;
        mid = (start + end) / 2;
        while (start <= end) {
            if (prefix[N] - prefix[mid] > now) { 
                start = mid + 1; 
            }
            else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        if (prefix[mid] - prefix[i] <= prefix[N] - prefix[mid]) {
            continue;
        }
        Idx = mid;
        start = i + 1;
        end = N - 1;
        while (start <= end) {
            if (prefix[mid] - prefix[i] > prefix[N] - prefix[mid]) {
                end = mid - 1;
            }
            else { 
                start = mid + 1; 
            }
            mid = (start + end) / 2;
        }
        ret += Idx - mid;
    }
    cout << ret<<"\n";
    return 0;
}
