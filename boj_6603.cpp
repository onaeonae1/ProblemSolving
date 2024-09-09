#include <iostream>
#include <vector>
using namespace std;
void comb(vector<int>& arr, vector<int>& selected, int start, int depth, int r) {
    if (depth == r) {
        for (int i = 0; i < selected.size(); ++i) {
            std::cout << selected[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = start; i < arr.size(); ++i) {
        selected[depth] = arr[i];
        comb(arr, selected, i + 1, depth + 1, r);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int r = 6; 
    int N;
    cin >> N;
    while (N != 0) {
        vector<int> arr(N);
        vector<int> selected(r);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        comb(arr, selected, 0, 0, r);
        cin >> N;
        cout << "\n";
    }
    return 0;
}
