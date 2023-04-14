#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
class Node {
public:
	int parentNum;
	int childCnt;
	int degree;
	int value;
	int ndesc;
	vector<int> road;
};
Node cities[300005];
int counting[300005];

int dfs(int cityNum, int parent, int degree) {
	// cout << "visiting city: " << cityNum << " from PARENT-> " << parent << endl;
	Node& city = cities[cityNum];
	city.parentNum = parent;
	city.degree = degree;
	int value = 0;
	int size = city.road.size(); 
	city.ndesc = 0;
	for (int i = 0; i < size; i++) {
		if (city.parentNum != city.road[i]) {
			city.childCnt = city.childCnt + 1;
			city.ndesc += dfs(city.road[i], cityNum, degree+1);
		}
	}
	// cout << "Visiting City: " << cityNum << " from parent-> " << parent << " with degree=> " << degree-city.ndesc << endl;
	return city.ndesc + 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n-1; i++) {
		int start;
		int end;
		cin >> start;
		cin >> end;
		cities[start].road.push_back(end);
		cities[end].road.push_back(start);
	}
	dfs(1,0,0);
	long long int ans = 0;
	for (int i = 1; i <= n; i++) {
		Node& city = cities[i];
		counting[i] = city.degree - city.ndesc;
	}
	sort(counting + 1, counting + n + 1, greater<>());
	for (int i = 1; i <= m; i++) {
		// cout << counting[i] << endl;
		ans += (long long int) counting[i];
	}
	cout << ans << endl;
	return 0;
}
