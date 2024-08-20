#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, M; 
    cin >> N >> M;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    ll start = 1;
    ll end = 1e9;
    ll mod = 0;
    ll sum = 0;
    while (start <= end) {
        ll mid = (start + end) / 2;
        ll sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= mid) sum += v[i] / mid;
        }
        if (sum >= M) {
            mod = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    for (int i = 0; i < v.size(); i++) { 
        sum += v[i] 
    };
    cout << sum - mod * M;
    return 0; 
}
