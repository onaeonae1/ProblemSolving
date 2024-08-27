#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct store {
	int y;
	int x;
	bool checked;
};

vector<pair<int, int>> houses;
vector<store> stores;
vector<int> selected;
int N, M;
int ans = 1e9;

void calculateDistance() {
	int total = 0;
	for (int i = 0; i < houses.size(); i++) {
		int houseY = houses[i].first;
		int houseX = houses[i].second;
		int currentMin = 1e9;
		for (int j = 0; j < stores.size(); j++) {
			if (stores[j].checked) {
				// 우리 식당 정상 운영합니다
				int storeY = stores[j].y;
				int storeX = stores[j].x;
				int dist = abs(storeY - houseY) + abs(storeX - houseX);
				currentMin = (currentMin > dist) ? dist : currentMin;
			}
		}
		total += currentMin;
	}
	ans = (ans < total) ? ans : total;
}

void do_selection(int index, int count) {
	// dfs + 조합
	// 폐업시키지 않을 치킨집 M개 고르기
	if (count == M) {
		calculateDistance();
	}
	for (int i = index; i < stores.size(); i++) {
		if (!stores[i].checked) {
			stores[i].checked = true;
			do_selection(i, count + 1);
			stores[i].checked = false;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int temp;
			cin >> temp;
			if (temp == 1) {
				//house!
				houses.push_back({ y,x });
			}
			if (temp == 2) {
				
				stores.push_back(
					{ y,x,false }
				);
			}
		}
	}
	do_selection(0, 0);
	cout << ans << "\n";
	return 0;
}
