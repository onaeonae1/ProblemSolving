#include<stdio.h>
#include<string.h>
#define SIZE 200005
char temp[SIZE];
char string[SIZE];
char key[SIZE];
int pi[SIZE];
//상태전이함수 생성
void kmp() {
	int n = strlen(key);
	int i = -1, j = 0;
	pi[j] = i;
	while (j < n) {
		if (i == -1 || (i >= 0 && key[i] == key[j])) {
			i++;
			j++;
			pi[j] = i;
		}
		else i = pi[i];
	}
}

//문자열 비교
int find_pattern() 
{
	int status = 0;
	int n = strlen(string);
	int m = strlen(key);
	int i = 0, j = 0;
	while (i < n) {
		if (j == -1 || (j >= 0 && string[i] == key[j]))
		{
			i++, j++;
		}
		else if (string[i] != key[j])
		{
			j = pi[j];
		}
		if (j == m)  //맞는 패턴 찾음
		{
			status = 1; 
			j = pi[j];
		}
	}
	return status;
}
void substring()
{
	int count = 0;
	for (int i = 0; i < strlen(temp); i++)
	{
		if (temp[i] >= 48 && temp[i] <= 57)
		{

		}
		else
		{
			string[count] = temp[i];
			count++;
		}
	}
}
int main()
{
	scanf("%s", temp);
	scanf("%s", key);
	substring();
	kmp();
	int result = find_pattern();
	printf("%d\n", result);
	return 0;
}
