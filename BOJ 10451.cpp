#include<stdio.h>
#define L 1005
typedef struct abc{
	int index;
	int value;
	int checked = 0;
}A;
void cycle(A b[], int nowindex, int startindex){
	b[nowindex].checked = 1;
	int nowvalue = b[nowindex].value;
	if (nowvalue == startindex) //현재 보고 있는 값이 시작한 인덱스와 같다면 현재 사이클을 종료.
	{
		return;
	}
	else
	{
		cycle(b, nowvalue, startindex); //다음 값을 검색한다.
		return;
	}
}
int main()
{
	int T; //테스트 케이스
	scanf("%d", &T);
	int results[L] = { 0, };
	for (int i = 1; i <= T; i++)
	{
		A board[L]; //index와 배열을 갖는 A구조체 board를 선언.
		int n;
		int count = 0;
		scanf("%d", &n); //순열의 길이

		for (int j = 1; j <= n; j++) //입력받는 과정
		{
			scanf("%d", &board[j].value);
			board[j].index = j; //인덱스를 넣어줌.
		}

		for (int j = 1; j <= n; j++) //검색 시작
		{
			if (board[j].checked == 0) //현재 보고 있는 인덱스의 값이 검색되지 않았던 값이라면
			{
				if (board[j].index == board[j].value) //인덱스와 값이 일치할 때
				{
					count++;
					board[j].checked = 1;
				}
				else{
					cycle(board, j, j);
					count++;
				}
			}
		}
		results[i] = count;
	}
	for (int i = 1; i <= T; i++){
		printf("%d\n", results[i]);
	}
}
