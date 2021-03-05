#include<iostream>
#include<string>
#define L 10005
using namespace std;

// z~a , 0
int memory = (1 << 27) - 1;
int words[L]; // 단어들 비트상태

int getBitmask(string temp) {
	int ret = 1;
	for (int i = 0; i < temp.size(); i++) {
		int tempBit = 1 << (temp[i] - 'a' + 1);
		ret |= tempBit;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words[i] = getBitmask(temp);
	}
	for (int i = 0; i < M; i++) {
		char oper, val;
		cin >> oper >> val;
		if (oper == '1') {
			// forget
			int bitValue = (1 << 27) - 1;
			bitValue^= (1 << (val - 'a' + 1));
			memory &= bitValue;
		}
		else {
			// remember
			int bitValue = 1 << (val - 'a' + 1);
			memory |= bitValue;
		}
		// memory 와 일치하는 bit들 순회
		int cnt = 0; 
		for (int j = 0; j < N; j++) {
			if ((words[j] & memory )== words[j]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}
