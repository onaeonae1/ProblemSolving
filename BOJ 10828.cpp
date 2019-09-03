#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void Push(vector<int>& V, int element) {
	V.push_back(element);
}
int Top(vector<int>& V) {
	int element = -1;
	if (V.empty() == false) {
		element = V.back();
	}
	return element;
}
int Size(vector<int> & V) {
	return V.size();
}
int Pop(vector<int> & V) {
	int element = -1;
	if (V.empty() == false) {
		element = V.back();
		V.pop_back();
	}
	return element;
}
int Empty(vector<int>& V) {
	int element = 0;
	if (V.empty() == true) {
		element = 1;
	}
	return element;
}
int main() {
	vector<int> V;
	vector<int> results;
	int n;
	cin >> n;
	while (n--) {
		string message;
		cin >> message;
		if (message == "push") {
			int value;
			cin >> value;
			Push(V, value);
		}
		if (message == "pop") {
			results.push_back(Pop(V));
		}
		if (message == "size") {
			results.push_back(Size(V));
		}
		if (message == "empty") {
			results.push_back(Empty(V));
		}
		if (message == "top") {
			results.push_back(Top(V));
		}
	}
	for (int i = 0; i < results.size(); i++) {
		cout << results.at(i) << endl;
	}
	return 0;
}
