#include<iostream>
#include<vector>
using namespace std;
vector<int> items;
vector<int> segtree;
vector<int> maxtree;
int N, M;
int make_segtree(int idx, int start, int end) {
	if (start == end) {
		segtree[idx] = items[start];
		return segtree[idx];
	}
	int m = (start + end) / 2;
	int left = make_segtree(idx * 2, start, m);
	int right = make_segtree(idx * 2 + 1, m + 1, end);
	segtree[idx] = (left < right) ? left : right; ///구간 내에서 제일 작은 놈 들고 있음
	return segtree[idx];
}
int make_maxtree(int idx, int start, int end) {
	if (start == end) {
		maxtree[idx] = items[start];
		return maxtree[idx];
	}
	int m = (start + end) / 2;
	int left = make_maxtree(idx * 2, start, m);
	int right = make_maxtree(idx * 2 + 1, m + 1, end);
	maxtree[idx] = (left < right) ? right : left; //구간 내에서 제일 큰 놈 들고 있음
	return maxtree[idx];
}
int do_query(int idx, int start, int end, int left, int right) {
	// 범위 체크
	if (left > end || right < start) {
		return 1e9;
	}
	if (left <= start && right >= end) {
		return segtree[idx];
	}

	int m = (start + end) / 2;
	int leftRet = do_query(idx * 2, start, m, left, right);
	int rightRet = do_query(idx * 2 + 1, m + 1, end, left, right);
	int ret = (leftRet < rightRet) ? leftRet : rightRet;
	return ret;
}

int do_maxquery(int idx, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && right >= end) {
		return maxtree[idx];
	}
	int m = (start + end) / 2;
	int leftRet = do_maxquery(idx * 2, start, m, left, right);
	int rightRet = do_maxquery(idx * 2 + 1, m + 1, end, left, right);
	int ret = (leftRet < rightRet) ? rightRet : leftRet;
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
	maxtree.resize(N * 4 + 1);
	// make segtree
	make_segtree(1, 0, N - 1);
	make_maxtree(1, 0, N - 1);

	// get and do query
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		int ret = do_query(1, 0, N - 1, t1, t2);
		int ret2 = do_maxquery(1, 0, N - 1, t1, t2);
		cout << ret << " " << ret2 << "\n";
	}
	return 0;
}
