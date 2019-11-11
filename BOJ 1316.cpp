#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n;
	int count = 0;
	vector<string> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < vec.size(); i++) {
		int check[50] = { 0, };
		string& message = vec.at(i);
		char prev = message.front();
		check[prev - 'a']++;
		bool flag = true;
		int j = 1;
		while (j < message.size() && flag == true) {
			char now = message.at(j);
			int idx = now - 'a';
			if (check[idx] !=0 && prev != now) {
				flag = false;
			}
			prev = now;
			check[idx]++;
			j++;
		}
		if (flag == true) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
