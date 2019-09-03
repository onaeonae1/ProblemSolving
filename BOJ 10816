//1 try success
//with upper_bound, lower_bound

#include<iostream>
#include<vector>
#include<algorithm>
#define limit 10000001
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<int> numbers; //숫자 담음
	vector<int> results; //결과 담음
	int m;
	cin >> m;
	numbers.push_back(-limit);
	for (int i = 0; i < m; i++) {
		int value;
		cin >> value;
		numbers.push_back(value);
	}
	numbers.push_back(limit);
	sort(numbers.begin(), numbers.end()); //정렬
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int key;
		cin >> key;
		vector<int>::iterator lower; //key 보다 아래
		vector<int>::iterator upper; //key 보다 위에
		upper = upper_bound(numbers.begin(), numbers.end(), key);
		lower = lower_bound(numbers.begin(), numbers.end(), key);
		int count = upper - lower;
		results.push_back(count);
	}
	for (int i = 0; i < results.size(); i++) {
		cout << results.at(i) <<" ";
	}
	return 0;
}
