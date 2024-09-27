#include<iostream>
#include<vector>
using namespace std;
vector<long long> items;
int N, M;
bool do_search(long long t) {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long temp = t / items[i];
        sum += temp;
        if (sum >= M) {
            break;
        }
    }
    bool isValid = (sum >= M);
    return isValid;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        items.push_back(t);
    }

    long long start = 1;
    long long end = 1e18;
    long long ret = 1e18;
    while (start <= end) {
        long long mid = (start + end) / 2;
        bool isValid = do_search(mid);
        //cout << mid << " " << isValid<< "\n";
        if (isValid) {
            ret = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}
