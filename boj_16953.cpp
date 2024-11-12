#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
map<string, long long> visit;
long long start, target;
struct item {
	string num;
	long long cnt;
};
long long bfs() {
	long long ans = -1;
	queue<item> jobq;
	jobq.push({ to_string(start), 0 });
	visit[to_string(start)] = 0;
	while (!jobq.empty()) {
		item now = jobq.front();
		jobq.pop();

		long long num = stoll(now.num);
		long long cnt = now.cnt;

		if (num == target) {
			ans = cnt;
			break;
		}

		if (num < target) {
			long long v1 = num * 2;
			long long v2 = (num * 10) + 1;
			if (visit.find(to_string(v1)) == visit.end()) {
				visit[to_string(v1)] = cnt+1;
				jobq.push({ to_string(v1), cnt + 1 });
			}
			if (visit.find(to_string(v2)) == visit.end()) {
				visit[to_string(v2)] = cnt + 1;
				jobq.push({ to_string(v2), cnt + 1 });
			}
		}
	}
	string targetS = to_string(target);
	ans = (visit.find(targetS) == visit.end()) ? -1 : visit[targetS];
	ans = (ans == -1 || ans == 0) ? ans : ans + 1;
	return ans;
	
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> start >> target;
	cout << bfs() << "\n";
	return 0;
}
