#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

bool check[15];
map<string, int> combination; //가능한 조합 목록
int maxLength[50]; //길이 n 짜리 특정 조합에 대해 몇 번이 최대로 생겼는지

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}
void powerSet(int index, string alpha, vector<int> course) { 
	int num = alpha.length();
	if (index == num) { //끝까지 봤음
		string temp;
		int count = 0;
		for (int i = 0; i < num; i++) {
			if (check[i]) {
				temp.push_back(alpha[i]);
				count++;
			}
		}
		//count 가 course 에 포함되는 값인지 봐야함
		bool flag = false;
		for (auto lim : course) {
			if (count == lim) {
				flag = true;
				break;
			}
		}
		if (flag) { //생성해도 문제 없다!
			int L = temp.length();
			combination[temp]++;
			maxLength[L] = (maxLength[L] < combination[temp] )? combination[temp] : maxLength[L]; 
		}
	}
	else {
		check[index] = true;
		powerSet(index + 1, alpha, course);
		check[index] = false;
		powerSet(index + 1, alpha, course);
	}
}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (auto alpha : orders) {
		sort(alpha.begin(), alpha.end()); //중복 방지를 위해 입력 문자열 사전순으로 정렬
		memset(check, 0, sizeof(check));
		powerSet(0, alpha, course);
	}
	vector<pair<string, int>> mp(combination.begin(), combination.end());
	sort(mp.begin(), mp.end(), compare);
	for (auto alpha : mp) {
		int c = alpha.second;
		if (c >= 2) { // 등장 횟수가 2번 이상
			int L = alpha.first.length();
			if (maxLength[L] == c) {
				answer.push_back(alpha.first);
			}
		}
		else {
			break;
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
