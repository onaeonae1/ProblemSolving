#include<iostream>
#include<vector>
using namespace std;
int n;
class Node {
public:
	int parentNum;
	int childCnt;
	vector<int> road;
};
Node cities[100005];

double dfs(int cityNum, int parent) {
	// cout << "visiting city: " << cityNum << " from PARENT-> " << parent << endl;
	Node& city = cities[cityNum];
	city.parentNum = parent;
	int size = city.road.size(); 
	double ans = 0.0;
	for (int i = 0; i < size; i++) {
		if (city.parentNum != city.road[i]) {
			city.childCnt = city.childCnt + 1;
			ans += 1 + dfs(city.road[i], cityNum);
		}
	}

	ans = city.childCnt == 0 ? 0.0 : ans / city.childCnt;
	// cout << "city: " <<cityNum<< " has answer -> " << ans << endl;
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int start;
		int end;
		cin >> start;
		cin >> end;
		cities[start].road.push_back(end);
		cities[end].road.push_back(start);
	}
	double ans = dfs(1, 0);
	printf("%.10lf\n", ans);
	
	return 0;
}
