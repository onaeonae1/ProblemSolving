#include<stdio.h>
long long int Settings(int num)
{
	return 3 * (num*num) + 3 * (num)+1;
}
int main()
{
	long long int Sum[50050];
	long long int index = 1;
	long long int request;
	int i, j, k;
	for (i = 0; i <= 50000; i++)
	{
		Sum[i] = Settings(i);
	}
	scanf("%lld", &request);
	if (request == 1)
	{
		printf("%lld", index);
	}
	else
	{
		while (1)
		{
			if (request > Sum[index - 1] && request <= Sum[index])
			{
				break;
			}
			index = index + 1;
		}
		index++;
		printf("%lld", index);
	}
	return 0;

}
