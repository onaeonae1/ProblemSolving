#include<iostream>
#define L 105
#define C 55
using namespace std;
int comp(int a, int b){
	if (a >= b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int c;
	int index = 0;
	int results[C] = { 0, };
	cin >> c;
	while (c--)
	{
		index++;
		int n; //삼각형의 높이
		int max = -1;
		int triangle[L][L] = { 0, }; //삼각형 값
		int table[L][L] = { 0, }; //최대의 값
		int paths[L][L] = { 0, }; //경로의 수
		cin >> n;\
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++){
				cin >> triangle[i][j]; //삼각형 값을 입력받고
				paths[i][j] = 1; //최소한 한 개의 경로를 가진다.
			}
		}

		table[1][1] = triangle[1][1];
		max = comp(max, table[1][1]);

		for (int j = 1; j <= n - 1; j++){
			for (int k = 1; k <= j; k++){
				int nowvalue = table[j][k]; //현재 내가 보고 있는 테이블의 값
				//바로 아래 값 갱신
				table[j + 1][k] = comp(table[j + 1][k], triangle[j + 1][k] + nowvalue);
				max = comp(max, table[j + 1][k]);

				//오른쪽 대각선 아래 값 갱신
				table[j + 1][k + 1] = comp(table[j + 1][k + 1], triangle[j + 1][k + 1] + nowvalue);
				max = comp(max, table[j + 1][k + 1]);
			}
			paths[j][1] = 1; //첫째자리는 항상 위에서만 경로를 받아온다.
		}
		paths[n][1] = 1; 
		for (int j = 2; j <= n; j++){
			for (int k = 1; k <= j; k++){
				if (k > 1 && k < j){
					int leftup = table[j - 1][k - 1]; //왼쪽 위
					int justup = table[j - 1][k]; //바로 위
					if (leftup == justup){ //같다면 두 경로에서 생기는 경우의 수를 합쳐준다.
						paths[j][k] = paths[j - 1][k - 1] + paths[j - 1][k]; 
					}
					else{ //그 외에는 큰 값을 가져오면 된다.
						if (leftup > justup){ 
							paths[j][k] = paths[j - 1][k - 1];
						}
						else if (leftup < justup){
							paths[j][k] = paths[j - 1][k];
						}
					}
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (table[n][i] == max) //마지막 열을 비교. 최대값이라면 그의 path를 저장
			{
				sum = sum + paths[n][i];
			}
		}
		results[index] = sum;
	}
	for (int i = 1; i <= index; i++){
		cout << results[i] << endl;
	}
	return 0;
}
