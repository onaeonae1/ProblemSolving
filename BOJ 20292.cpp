#include<iostream>
#include<map>
#include<string>
using namespace std;  
map<string, bool> write, read;
void wait() {
	cout << "WAIT" << "\n";
	write.clear();
	read.clear();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string oper;
	while (true) {
		string a, to, b;
		cin >> oper;
		if (oper == "EXIT") {
			break;
		}
		else if (oper == "WRITE") {
			cin >> a >> to >> b;
			// b가 read 중이거나, a  b 에 값이 들어오는 경우
			if (read[b] || write[a] || write[b]) {
				wait();
			}
			cout << "WRITE " << a << " " << "TO " << b << "\n";
			read[a] = true;
			write[b] = true;
		}
		else { //read
			cin >> a;
			//a에 값이 들어오고 있는 경우
			if (write[a]) {
				wait();
			}
			cout << "READ" << " " << a << "\n";
			read[a] = true;
		}
	}
	cout << "EXIT" << endl;
    return 0;
}
