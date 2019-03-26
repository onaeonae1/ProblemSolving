#include<iostream>
#include<vector>
#include<algorithm>
#define L 1000005
#define INF 1000005
using namespace std;
int main()
{
	int l; //수열의 길이
	cin >> l;
	vector<int> v; //DP에 사용할 벡터
	v.push_back(-INF);
	int answer = 0;
	for (int j = 1; j <= l; j++)
	{
		int value;
		cin >> value;
		//현재 수열의 요소가 벡터의 끝 값보다 크다면,
		if (v.back() < value) //벡터의 끝에 추가시켜주고 answer++
		{
			v.push_back(value);
			answer++;
		}
		//만약 수열의 요소가 벡터의 끝보다 작다면,
		else
		{
			//lower_bound(이진 탐색. logn)로 수열의 요소가 들어갈 위치를 찾아줌
			auto it = lower_bound(v.begin(), v.end(), value);
			*it = value;
		}
	}
	cout << answer;
	return 0;
}
