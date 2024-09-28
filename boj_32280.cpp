#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
vector<int> students;
vector<string> split(string str, char Delimiter) {
	istringstream iss(str);             
	string buffer;                      
	vector<string> result;
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);           
	}
	return result;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int ts = 0;
	for (int i = 0; i <= N; i++) {
		string t, p;
		cin >> t >> p;
		vector<string> times = split(t, ':');
		int hour = stoi(times[0]);
		int min = stoi(times[1]);
		int s = ((60 * hour) + min);
		if (p == "student") {
			students.push_back(s);
		}
		else {
			ts = s;
		}
	}
	int ds = 0;
	string tt;
	cin >> tt;
	vector<string> tts = split(tt, ':');
	ds = (60 * stoi(tts[0])) + (stoi(tts[1]));
	int ret = 0;
	for (int n : students) {
		if (n >= ds && n >= ts) {
			ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}
