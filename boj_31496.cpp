#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int N;
string s;
int main() {
	int cnt = 0;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> s;
	while (N--) {
		string temp;
		int t;
		cin >> temp >> t;
		if (temp == s) {
			cnt += t;
		}
		else {
			auto start = 0;
			auto end = temp.find("_");
			bool is_done = false;
			vector<string> tokens;
			
			while (end != std::string::npos) {
				string q = temp.substr(start, end - start);
				if (q == s) {
					cnt += t;
					break;
				}
				tokens.push_back(temp.substr(start, end - start));
				start = end + 1;
				end = temp.find('_', start);
			}
			string q = temp.substr(start);
			if (q == s) {
				cnt += t;
			}

		}
	}
	cout << cnt << "\n";
	return 0;
}
