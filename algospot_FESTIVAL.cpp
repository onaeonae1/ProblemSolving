#include<iostream>
#define INF 99999999
#define L 1005
#define T 105
using namespace std;
int main()
{
	double answer[T] = { 0, };
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++)
	{
		int n, l;
		cin >> n >> l;
		int sum[L] = { 0, };
		for (int j = 1; j <= n; j++)
		{
			cin >> sum[j];
			sum[j] = sum[j] + sum[j - 1];
		}
		double min = INF;
		for (int j = 0; j <= n - l + 1; j++)
		{
			for (int k = j + l; k <= n; k++)
			{
				int value = sum[k] - sum[j];
				double result = (double(value) / (k - j));
				if (min >= result)
				{
					min = result;
				}
			}
		}
		answer[i] = min;
	}
	cout << fixed;
	cout.precision(8);
	for (int i = 1; i <= c; i++)
	{
		cout << answer[i] << endl;
	}
	return 0;
}
