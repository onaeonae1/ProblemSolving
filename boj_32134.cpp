#include<iostream>
#include<vector>
using namespace std;
long long N, H, S;
int main() {
    cin >> N >> H >> S;
    vector<long long> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }

    long double alpha = 0;
    long double beta = 0;

    // 높이에 따라 사다리꼴 혹은 삼각형 결정만 해주면 됨
    double startHeight = 0;
    double endHeight = 0;
    double exp = ((double)S / (double)N) * 2.0;
    if (exp > H) {
        endHeight = H;
        startHeight = exp - H;
    }
    else {
        startHeight = 0;
        endHeight = exp;
    }


    double unit = (endHeight - startHeight) / N; 
    double longer = startHeight;
    double shorter = longer + unit;
    for (int i = 0; i < N; i++) {
        alpha += (longer + shorter) * items[i] / 2;
        longer += unit;
        shorter += unit;
    }
    longer = startHeight;
    shorter = longer + unit;
    for (int i = N - 1; i >= 0; i--) {
        beta += (longer + shorter) * items[i] / 2;
        longer += unit;
        shorter += unit;
    }

    alpha = (alpha < beta) ? alpha : beta;
    cout << fixed;
    cout.precision(6);
    cout << alpha << "\n";
    return 0;
}
