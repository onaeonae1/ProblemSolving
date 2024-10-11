#include<iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	int cnt = 0;
	string s;
	cin >> N;
	cin >> s;
	// i : 시작 j: 끝
	for (int i = 0; i < N-1; i++) {
		char start = s[i];
		for (int j = i + 1; j < N; j++) {
			char end = s[j];
			if (start == 'A' && end == 'A' && (j-i >=2)) {
				// 넌 검사받을 자격이 있다
				int NCount = 0;
				int Acount = 0;
				bool isValid = false;
				for (int k = i; k <= j; k++) {
					if (s[k] == 'N') {
						NCount++;
					}
					if (s[k] == 'A') {
						Acount++;
					}
					if(NCount>2 || Acount>3){
						break;
					}
				}
				isValid = (NCount==1) && (Acount==2);
				if (isValid) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";
}
