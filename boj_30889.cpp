#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N;
vector<string> items;
int table[50][50];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		string numarea;
		for (int j = 1; j < temp.length(); j++) {
			numarea.push_back(temp.at(j));
		}
		int ypos = int(temp.at(0)) - int('A');
		int xpos = stoi(numarea)-1;
		table[ypos][xpos] = 1;
	}
	for (int i = 0; i <= int('J') - int('A'); i++) {
		for (int j = 0; j < 20; j++) {
			if (table[i][j] == 1) {
				printf("o");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
