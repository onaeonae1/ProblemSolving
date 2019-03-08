#include<stdio.h>
#include<algorithm>
#define SIZE 1005
#define INF 1123456789
using namespace std;
struct abc
{
	int value; //능력치
	int group; //반
};
bool compare(const abc &a, const abc &b)
{
	return a.value < b.value; //값이 같을 경우는 어차피 없으므로 그냥 이렇게 오름차순으로 정렬
}
int check_filled(int checked[], int n) //꽉 찼는지 체크하는 기능
{
	for (int i = 1; i <= n; i++)
	{
		if (checked[i] == 0) //중간에 하나라도 안 차면
		{
			return 0;
		}
	}
	return 1; //만약 다 찼다면
}
int main()
{
	int n, m;
	abc B[SIZE*SIZE];
	int result = INF; //결과
	int checked[SIZE] = { 0, }; //체크 배열. 그 반에서 값이 나왔는지 확인함.
	scanf("%d %d", &n, &m); //반의 수
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int pos = (i - 1)*m + j;
			scanf("%d", &B[pos].value); 
			B[pos].group = i;
		}
	}
	int sum = n * m;
	sort(B + 1, B +(sum)+1, compare); //전체 데이터들을 능력치 크기에 따라 정렬
	//동적의 시작
	int head = 2; //머리를 담당
	int tail = 1; //꼬리를 담당
	checked[B[head].group]++;
	checked[B[tail].group]++;
	B[sum + 1].value = INF;
	while (1)
	{
		if (tail > sum-n)
		{
			break;
		}
		int check_result = check_filled(checked,n);
		if (check_result == 1) //모든 반에서 뽑았다는 거임.
		{
			int dif = (B[head].value - B[tail].value); //head는 제일 끝, tail은 제일 앞이므로 최대, 최소임.
			if (dif <= result && dif>=2)
			{
				result = dif;
			}
			checked[B[tail].group]--; //이 칸은 이제 버린 것.
			tail++;
		}
		else if(check_result==0)//모든 반에서 뽑힌 것이 아님
		{
			//뒤로 한 칸 이동하여 큐를 늘린다.
			if (head < sum)
			{
				head++;
				checked[B[head].group]++; //새로운 칸이 추가됨.
			}
			else
			{
				checked[tail]--;
				tail++;
			}
		}
	}
	printf("%d", result);
	return 0;
}
