#include<iostream>
#include<string>
#define L 100005
using namespace std;
string people[L];
int results[L];
int main() {
	int N;
	cin >> N;
	getchar();
	for (int i = 1; i <= N; i++) {
		string s;
		getline(cin, s);
		int gc = 0;
		int bc = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'g' || s[i]=='G') {
				gc++;
			}
			else if (s[i] == 'b' || s[i]=='B') {
				bc++;
			}
		}
		if (gc == bc) {
			results[i] = 0; //neutral
		}
		else {
			if (gc > bc) {
				results[i] = 1; //good
			}
			else {
				results[i] = -1; //bad
			}
		}
		people[i] = s;
	}
	for (int i = 1; i <= N; i++) {
		cout << people[i]<<" is ";
		if (results[i] == 0) {
			cout << "NEUTRAL" << endl;
		}
		if (results[i] == -1 ) {
			cout << "A BADDY" << endl;
		}
		if (results[i] == 1) {
			cout << "GOOD" << endl;
		}
	}
	return 0;
}
