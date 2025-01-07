#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int,int>> points;
int N;
double get_area() {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        long long x1 = points[i].first, y1 = points[i].second;
        long long x2 = points[(i + 1) % N].first, y2 = points[(i + 1) % N].second;
        sum += x1 * y2 - y1 * x2;  // 신발끈
    }

    return abs(sum) / 2.0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({ x, y });
    }

    cout.precision(1);
    cout << fixed << get_area() << "\n";

    return 0;
}
