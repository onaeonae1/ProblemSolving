#include<iostream>
#include<string>
#include<deque>
#define L 105
using namespace std;
int search(deque<pair<string, int>> &dic, int n) { 
	int varicount = 0;
	for (int i = 0; i < n; i++) {
		int status = 0;
		string s1, s2;
		cin >> s1 >> s2;
		int v = dic.size();
		for (int j = 0; j < v; j++) { //종류 같은 것이 있는지
			if (dic.at(j).first == s2) {
				status = 1;
				dic.at(j).second++;
				break;
			}
		}
		if (status == 0) { //같은 종류가 없었음
			varicount++;
			pair<string, int> p;
			p.first = s2; p.second = 1;
			dic.push_back(p);
		}
	}
	return varicount;
}
int main() {
	int c; //테스트 케이스
	cin >> c;
	int index = 0;
	int results[L] = { 0, }; 
	while (c--) {
		deque<pair<string, int>> dic;
		int n;
		cin >> n;
		int varicount = search(dic, n);
		int answer = 1;
		for (int i = 0; i < varicount; i++) {
			int temp = (dic.at(i).second + 1);
			answer = answer * temp;
		}
		results[index] = --answer;
		index++;
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
