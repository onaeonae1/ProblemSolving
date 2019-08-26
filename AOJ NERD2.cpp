#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int, int> coords; //오른쪽 위에 위치하는(== 갯수를 세야 하는) 점들
bool isDominated(int x, int y) {
	map<int, int> ::iterator it = coords.lower_bound(x); //현재 들어온 점의 오른쪽에 위치한 점 찾기
	if (it == coords.end()) {	return false; } 
	return y < it->second;  //높이 비교한 결과
}
void removeDominated(int x, int y) { //현재 들어온 점에 포함되는 점 제거
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin()) { return; }
	it--;
	while (true) {
		if (it->second > y) { break; }
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int> ::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y) == true) { return coords.size(); }
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
int main() {
	int c;
	int index = 0; 
	int results[55] = { 0, };
	cin >> c;
	while (c--) {
		int count = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			count += registered(x, y);
		}
		results[index] = count;
		index++;
		coords.clear(); //사용한 map 을 비운다.
	}
	for (int i = 0; i < index; i++) {
		cout << results[i] << endl;
	}
	return 0;
}
