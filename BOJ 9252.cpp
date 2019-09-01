#include<iostream>
#include<string>
#include<vector>
using namespace std;
int cache[1005][1005]; //0으로 초기화됨
int max(int a, int b) {
	if (a <= b) {
		return b;
	}
	else {
		return a;
	}
}
int LCS(string& x, string &y) { //LCS의 '길이' 리턴
	for (int i = 1; i <= y.size(); i++) {
		for (int j = 1; j <= x.size(); j++) {
			if (y.at(i - 1) == x.at(j - 1)) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}
	return cache[y.size()][x.size()];
}
// m = y.size();
// n = x.size():
string ret;
void tracking(string& x, string &y, int m , int n) {
	if (m == 0 || n == 0) {
		return;
	}
	if (cache[m][n] > cache[m - 1][n - 1] && cache[m][n] > cache[m][n - 1] && cache[m][n] > cache[m - 1][n]) {
		ret += x[n - 1];
		tracking(x, y, m - 1, n - 1);
	}
	else if (cache[m][n] > cache[m - 1][n] && cache[m][n] == cache[m][n - 1]) {
		tracking(x, y, m, n - 1);
	}
	else {
		tracking(x ,y, m - 1, n);
	}
}
int main() {
	string alpha; 
	string beta;
	//문자열 2개 입력받기
	cin >> alpha; //x 
	cin >> beta; //y
	int value = LCS(alpha, beta);
	tracking(alpha, beta, beta.size(), alpha.size());
	string ans;
	for (int i = ret.size() - 1; i >= 0; i--) {
		ans.push_back(ret.at(i));
	}
	cout << value << endl;
	cout << ans << endl;
	return 0;
}
