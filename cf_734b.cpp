#include<iostream>

using namespace std;


int min(int a, int b) {
	int retValue;
	retValue = (a < b) ? a : b;
	return retValue;
}

int main(void){
	int LIMIT = 5000005;
	int k2, k3, k5, k6;
	int sum = 0;


	cin >> k2 >> k3 >> k5 >> k6;

	// make 256 first
	int	alphaValue = LIMIT;
	int betaValue = LIMIT;
	alphaValue = min(k5, k6);
	alphaValue = min(k2, alphaValue);

	if (alphaValue > 0 && alphaValue!= LIMIT) {
		sum += (256 * alphaValue);
		k2 -= alphaValue;
		k5 -= alphaValue;
		k6 -= alphaValue;
	}
	betaValue = min(k2, k3);
	if (betaValue > 0 && betaValue != LIMIT) {
		sum += (32 * betaValue);
		k2 -= betaValue;
		k3 -= betaValue;
	}

	cout << sum << endl;
	return 0;
} 
