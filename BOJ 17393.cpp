#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<long long int> A;
	vector<long long int> B;
	vector<long long int> results;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { //잉크
		long long int value;
		cin >> value;
		A.push_back(value);
	}
	for (int i = 0; i < n; i++) { //점도(오름차순임)
		long long int value;
		cin >> value;
		B.push_back(value);
	}
	vector<long long int> ::iterator now = B.begin();
	for (int i = 0; i < n; i++) {
		vector<long long int>::iterator target;		
		//key값 이상의 값을 가진 원소의 위치를 리턴
		target = upper_bound(++now, B.end(), A.at(i));
		results.push_back(target-now);
	}
	for (int i = 0; i < results.size(); i++) {
		cout << results.at(i) << " ";
	}
	return 0;
}
