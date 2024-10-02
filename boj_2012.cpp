#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long total = 0;

    for (int i = 0; i < N; i++) {
        long long t = (i + 1) - v[i];
        t = (t <= 0) ? t * -1 : t;
        total += t;
    }

    cout << total;
    return 0;
}
