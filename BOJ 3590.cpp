#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string, string> dict; //축약어 사전
set<string> ambiguous; // 모호함 체크용
bool isAlpha(char c) { //알파벳 체크
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
		return true;
	}
	else {
		return false;
	}
}
char toUpper(char c) {
	if ('a' <= c && c <= 'z') {
		return c = c - 32;
	}
	else if('A'<=c && c <='Z'){
		return c;
	}
	else {
		return '@';
	}
}
char toLower(char C){
	if ('A' <= C && C <= 'Z') {
		return C = C + 32;
	}
	else if('a'<=C && C<='z'){
		return C;
	}
	else {
		return '@';
	}
}
int getCase(char c) {
	if ('a' <= c && c <= 'z') { //소
		return 0;
	}
	else { //대
		return 1;
	}
}
int isAbbr(string token) { //축약어인지 확인해줌. -2, -1, 0, 양수 의 값을 리턴 그에 따른 처리필요
	if (token.size() <= 2) {
		return -2; // 단어 처리 자체를 고려하지 않고 그대로 출력
	}
	int ret = 0;
	if (isAlpha(token.front()) && isAlpha(token.back())) {
		for (int i = 1; i < token.size() - 1; i++) {
			if (token[i] >= '0' && token[i] <= '9') {
				ret = ret * 10 + (token[i] - '0');
			}
			else {
				return -1; // 축약어가 아닌 단어. 이후 처리 필요
			}
		}
		return ret; //가운데 숫자 리턴
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string line, token;
	while (getline(cin, line)) {
		line.push_back('@'); //끝 마킹
		for (char c : line) {
			if (isAlpha(c) || ('0' <=c && c<='9')) { //알파벳 혹은 숫자만 가져오기
				token.push_back(c);
			}
			else {
				if (token.size()!=0) { //만들어진 단어에 대해 
					int abbcase = isAbbr(token);
					if (abbcase == -2) { //두자리 글자. 그대로 출력하기
						cout << token;
					}
					else if (abbcase == -1) { //일반 단어.
						// 일단 출력하기
						cout << token;
						// 축약어 형태로 변환-> dict에 저장하기 위해. 소문자/숫자/소문자 형태로
						string abbToken = toLower(token.front()) + to_string(token.size() - 2) + toLower(token.back());
						if (dict.find(abbToken) == dict.end()) {
							dict[abbToken] = token;
						}
						else { //이미 사전에 존재하는 단어 -> 모호함 체크 필요
							for (int i = 1; i < dict[abbToken].size(); i++) {
								// 사전에 존재하는 것과 다른지 체크. 다르다면 모호함 set에 추가
								if (toLower(dict[abbToken][i]) != toLower(token[i])) {
									ambiguous.insert(abbToken);
									break;
								}
							}
						}
					}
					else { // abbcase>=0 따라서 축약어
						string abbToken = toLower(token.front()) + to_string(abbcase) + toLower(token.back());
						if (dict.find(abbToken) == dict.end() || ambiguous.find(abbToken) != ambiguous.end()) {
							// 사전에 없거나 모호함에 걸리는 경우
							cout << token;
						}
						else { //사전에서 가져와야 함
							// 모두 대문자 처리 필요한 경우
							bool allUpper = getCase(token.front()) && getCase(token.back());
							// 앞은 그대로 출력하고 뒤의 문자들 출력하기
							cout << token.front();
							for (int i = 1; i < dict[abbToken].size(); i++) {
								if (allUpper) cout << toUpper(dict[abbToken][i]);
								else cout << toLower(dict[abbToken][i]);
							}
						}
					}
					token = "";
				}
				if (c != '@') cout << c;
			}
		}
		cout << "\n";
	}
}
