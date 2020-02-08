#include<iostream>
#include<string>
#include<map>
using namespace std;
void PrintCache(string cache) {
	cout << cache << endl;
}
void process(string buffer, int size, map<char, int>& legend) {
	string cache = "";
	for (int i = 0; i < buffer.size(); i++) {
		char now = buffer.at(i);
		if (now == '!') { //출력 명령
			PrintCache(cache);
		}
		else { //검사할 필요 있음
			int value = legend[now];
			if (value == 0) { //등장한 적 없음
				if (cache.size() == size) { //사이즈 꽉참
					char front = cache.front();
					legend[front]--;
					cache = cache.substr(1); //0번째 버림
					cache.push_back(now);
					legend[now]++;
				}
				else { //사이즈 꽉 안참 -> 그냥 추가해주면 됨
					cache.push_back(now);
					legend[now]++;
				}
			}
			else { //등장한 적 있음 -> 자리이동만 필요. 맵 조작필요 X
				int target = cache.find(now);
				string front = cache.substr(0, target);
				string next = cache.substr(target+1);
				cache = front + next;
				cache.push_back(now);
			}
		}
	}
}
void initMap(map<char, int>& legend) { //맵 초기화
	legend.clear();
	char element = 'A';
	for (int i = 0; i < 26; i++) {
		legend.insert(make_pair(element, 0));
		element++;
	}
}
int main() {
	map<char, int> legend;
	int n;
	int size; //캐시 사이즈
	cin >> size;
	int count = 0;
	while (size!=0) {
		initMap(legend);
		string buffer;
		cin >> buffer;
		cout << "Simulation" << " " << ++count << endl;
		process(buffer, size, legend);
		buffer.clear();
		cin >> size;
	}
	return 0;
}
