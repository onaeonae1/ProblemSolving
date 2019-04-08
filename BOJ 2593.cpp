#include<stdio.h>
#define N 500001
struct abc
{
	int height; //높이
	int index; // 순서
}DATA[N];
struct def
{
	int sheight; //걸리는 높이
	int sindex; //그것의 위치
}stack[N];
int ans[N]; //각 탑 별 걸리는 위치 - > 정답
int main()
{
	DATA[0].height = 100000001;
	DATA[0].index = 0;
	stack[0].sheight = 100000001;
	stack[0].sindex = 0;
	int i, j, k;
	int n;
	int stackmove = 1;
	int maxvalue = 1; //최대값이 계속 앞을 보는것을 방지하기 위한 것.
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &DATA[i].height);
		DATA[i].index = i;
		if (i == 1) //첫번째 탑은 당연히 걸리지 않는다.
		{
			stack[stackmove].sheight = DATA[1].height;
			stack[stackmove].sindex = 1;
			ans[1] = 0;
			stackmove++;
			continue;
		}
		while (1)
		{
			int nowheight = DATA[i].height;
			int prevheight = stack[stackmove].sheight;
			if (nowheight > prevheight) //지금 것이 스택의 끝값보다 크면 안걸리니까 더 큰놈을 찾음
			{
				stack[stackmove].sheight = 0;
				stack[stackmove].sindex = 0;
				stackmove--;
			}
			else if (nowheight <= prevheight) //이제 걸리는거임
			{
				int previndex = stack[stackmove].sindex;
				stackmove++;
				stack[stackmove].sheight = nowheight;
				stack[stackmove].sindex = i;
				ans[i] = previndex;
				break;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}
