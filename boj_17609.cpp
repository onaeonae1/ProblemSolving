#include<iostream>
#include<string>
using namespace std;
int do_search(int head, int tail, string s, int isSpecial) {
	while (head < tail) {
		if (s[head] != s[tail]) {
			if (isSpecial==0) { //특별 검사를 허용한다
				int left = do_search(head + 1, tail, s, 1);
				int right = do_search(head, tail - 1, s, 1);
				if (left == 0 || right == 0) {
					return 1;
				}
				else {
					return 2;
				}
			}
			else {
				return 2;
			}
		}
		else {
			head++;
			tail--;
		}
	}
	return 0;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int ret = do_search(0, s.size() - 1, s, 0);
		cout << ret << "\n";
	}


	return 0;
}
