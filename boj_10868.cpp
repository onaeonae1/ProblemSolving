#include<iostream>
#include<vector>
using namespace std;
vector<int> items;
vector<int> segtree;
int N, M;
int make_segtree(int idx, int start, int end) {
	if (start == end) {
		segtree[idx] = items[start];
		return segtree[idx];
	}
	int m = (start + end) / 2;
	int left = make_segtree(idx * 2, start , m);
	int right = make_segtree(idx * 2 + 1, m + 1, end);
	segtree[idx] = (left < right) ? left : right; ///구간 내에서 제일 작은 놈 들고 있음
	return segtree[idx];
}
int do_query(int idx, int start, int end, int left, int right) {
	// 범위 체크
	if (left> end || right<start) {
		return 1e9;
	}
	if (left <= start && right >= end) {
		return segtree[idx];
	}

	int m = (start + end) / 2;
	int leftRet = do_query(idx*2, start, m, left, right);
	int rightRet = do_query(idx*2+1, m+1, end, left, right);
	int ret = (leftRet < rightRet) ? leftRet : rightRet;
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		items.push_back(t);
	}
	segtree.resize(N * 4 + 1); // 일단 4배 정도로
	// make segtree
	make_segtree(1, 0, N - 1);


	// get and do query
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		int ret = do_query(1, 0, N - 1, t1, t2);
		cout << ret << "\n";
	}
	return 0;
}
