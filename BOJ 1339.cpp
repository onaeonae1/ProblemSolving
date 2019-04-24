#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int alpha_value[30];
int N;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> N;
	cin.clear();
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		int tenvalue = 1;
		for (int j = s.length()-1; j >=0; j--) {
			int alpha = s[j] - 'A';
			alpha_value[alpha] += tenvalue;
			tenvalue *= 10;
		}
	}
	sort(alpha_value + 0, alpha_value + 30 + 0, compare );
	int integerValues = 9;
	int result = 0;
	for (int i = 0; i < 30; i++) {
		if (alpha_value[i] == 0) {
			break;
		}
		else {
			result += alpha_value[i] * integerValues;
			integerValues--;
		}
	}
	cout << result << endl;
	return 0;
}
