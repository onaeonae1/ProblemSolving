#include<stdio.h>
#include<algorithm>
#include<queue>
#define lim 30005 
using namespace std;
int main()
{
	int n, d, k, c;
	int A[lim] = { 0, }; //초밥 리스트
	int check[lim] = { 0, };
	int max = -1;
	queue<int> q; //초밥을 탐색하며 사용할 queue를 선언
	scanf("%d %d %d %d", &n, &d, &k, &c); //초밥수, 가짓수, 연속가능수, 쿠폰값
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]); //초밥 리스트 입력받음.
	}
	for (int i = 0; i < k; i++)
	{
		q.push(A[i]);
		if (check[A[i]] == 0)
		{
			count++;
		}
		check[A[i]]++;
		if (count >= max)
		{
			max = count;
		}
	}
	for (int i = k; i < n + k; i++)
	{
		int head = i % (n); //앞으로 나아가며
		q.push(A[head]); //새로운 값을 추가
		if (check[A[head]] == 0)
		{
			count++;
		}
		check[A[head]]++;
		if (check[q.front()] == 1)
		{
			count--;
		}
		check[q.front()]--;
		q.pop();
		if (check[c] == 0) //쿠폰은 무조건 추가
		{
			check[c] = 1; 
			count++;
		}
		if (count >= max)
		{
			max = count; 
		}
	}
	printf("%d", max);
	return 0;
}
