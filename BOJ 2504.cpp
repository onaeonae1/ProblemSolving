#include<stdio.h>
#include<string.h>
#define L 150
char line[L];
int steps[L];
int check1, check2, check3, check4;
int main()
{
	scanf("%s", line);
	int step = 0;
	for (int i = 0; i < strlen(line); i++) //깊이 체크해줌.
	{
		if (line[i] == '(' || line[i] == '[')
		{
			if (line[i] == '(')
			{
				check1++;
			}
			if (line[i] == '[')
			{
				check3++;
			}
			step++;
			steps[i+1] = step;
		}
		else if (line[i] == ')' || line[i] ==']')
		{
			if (line[i] == ')')
			{
				check2++;
			}
			if (line[i] == ']')
			{
				check4++;
			}
			step--;
			steps[i+1] = step;
		}
	}
	long long int multiply = 1;
	long long int count = 0;
	if ((check1 != check2) || (check3 != check4))
	{
		printf("0");
		return 0;
	}
	for (int i = 1; i<= strlen(line); i++)
	{	
		char alpha = line[i - 1];
		int now = steps[i];
		int prev = steps[i - 1];
		if (now > prev) //괄호가 열린다
		{
			if (alpha == '(')
			{
				multiply = multiply * 2;
			}
			else if (alpha == '[')
			{
				multiply = multiply * 3;
			}
			
			if (steps[i + 1] < now) //열리자 마자 닫힌 것.
			{ 
				//현재 조회중인 것은 열려있는 상태. 다만 그 뒤를 볼 뿐이다.
				if ((alpha == '(' && line[i] == ']') || (alpha=='[' && line[i]==')'))
				{
					count = 0;
					break;
				}
				else
				{
					count = count + multiply;
				}
			}
		}
		else
		{
			if (alpha == ')')
			{
				multiply = multiply / 2;
			}
			else if(alpha ==']')
			{
				multiply = multiply / 3;
			}
		}
	}
	printf("%lld\n", count);
	return 0;
}
