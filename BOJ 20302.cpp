#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string temp = "";
	string numStr = "";
	char now = '*';
	ll mulvalue = 1;
	ll divvalue = 1;
	int count = 0;
	scanf("%d", &n);
	ll* nowvalue = &mulvalue;
	while (count<n-1) { //연산자로 갯수 셈
		cin >> temp;
		nowvalue = (now == '*') ? &mulvalue : &divvalue;
		if (temp[0] == '*') {
			count++;
			*nowvalue *= (ll)(stoll(numStr));
			now = '*';
			numStr = "";
		}
		else if (temp[0]=='/') {
			count++;
			*nowvalue *= (ll)(stoll(numStr));
			now = '/';
			numStr = "";
		}
		else {
			numStr = temp;
		}
		getchar();
	}
	cin >> temp;
	nowvalue = (now == '*') ? &mulvalue : &divvalue;
	*nowvalue *= (ll)(stoll(temp));

	if (mulvalue%divvalue == 0) {
		cout << "mint chocolate"<<"\n";
	}
	else {
		cout << "toothpaste"<<"\n";
	}

	return 0;
}
