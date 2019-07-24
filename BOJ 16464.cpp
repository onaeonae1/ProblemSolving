#include<iostream>
#define INF 1005
int main(){
	int n;
	cin>>n;
	int A[INF] = { 0, };
	int binarytable[INF];
	int value = 1;
	for (int i = 0; i <= 30; i++){
		binarytable[i] = value;
		value = value * 2;
	}
	int temp;
	for (int i = 1; i <= n; i++){
		cin>>temp; //딜러가 뽑은 수
		for (int j = 0; j <= 30; j++){
			if (temp == binarytable[j]) {
				A[i] = 1; //이 숫자는 표현할 수 없음
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (A[i] == 0){ //표현 가능
			cout<<"Gazua"<<endl;
		}
		else if (A[i] == 1){ //표현 불가
			cout<<"GoHanGang"<<endl;
		}
	}
	return 0;
}
