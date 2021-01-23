// 0000.. 01 : 아무것도 없음
// 0000.. 11 : a 만 있음
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> wordsVector;
int answer;
int c;
int fullCombination = (1 << 26) - 1;
void solve(int index, int state) {
	//index : 확인중인 word
	//state : 현재 bitmask의 상태
	if (index == c-1) {
		if (state == fullCombination) {
			answer++;
		}
		return;
	}
	else {
		solve(index + 1, state | wordsVector[index + 1]); //다음 word를 포함
		solve(index + 1, state); //다음 word를 포함시키지 않음
	}
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	scanf("%d", &c);
	for(int i=0; i<c; i++) {
		string word;
		cin >> word;
		int temp = 0;
		for (int j = 0; j < word.size(); j++) {
			temp = temp | (1 << word.at(j) - 'a');
		}
		wordsVector.push_back(temp);
	}
	solve(-1, 0);
	printf("%d\n", answer);
	return 0;
}
