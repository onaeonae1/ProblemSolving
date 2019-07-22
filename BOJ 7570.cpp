#include<iostream>
#define N 1000001
int A[N] = { 0 };
int main(){
	int i, j, k;
	int n;
	int a;
	cin>>n;
	int max = -9999;
	for (i = 1; i <= n; i++){
		cin>>a;
		A[a] = A[a - 1] + 1;
		if (A[a] > max){
			max = A[a];
		}
	}
	int ans = n - max;
	cout<<ans;
	return 0;
}
