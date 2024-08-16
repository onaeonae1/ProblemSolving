#include<iostream>
#include<climits>
using namespace std;

long long int A[100005];

int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    int start = 0;
    int end = N - 1;
    long long int ans = LLONG_MAX;
    long long int p1 = A[start];
    long long int p2 = A[end];

    while (start < end) {
        long long int stv = A[start];
        long long int edv = A[end];

        long long int mix = stv + edv;

        if (abs(mix) < abs(ans)) {
            ans = mix;
            p1 = stv;
            p2 = edv;
        }

        if (mix < 0) {
            start++;
        }
        else if (mix > 0) {
            end--;
        }
        else {
            break;
        }
    }

    printf("%lld %lld", p1, p2);

    return 0;
}
