#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second; // 빈도수가 높은 순
	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length(); // 길이가 긴 순
	return a.first < b.first; // 알파벳 순
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	map<string, int> wordCount;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string word;
		cin >> word;
		if (word.length() >= M) {
			wordCount[word]++;
		}
	}
	vector<pair<string, int>> words(wordCount.begin(), wordCount.end());

	// 정렬
	sort(words.begin(), words.end(), compare);

	// 출력
	for (const auto& word : words) {
		cout << word.first << '\n';
	}
	return 0;
}
