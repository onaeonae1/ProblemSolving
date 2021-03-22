using namespace std;
long long gcd(long long a, long long b){
    long long temp;
    if(a<=b){
        temp = a;
        a = b;
        b = temp;
    }
    while(b!=0){
        temp =  a % b;
        a = b;
        b = temp;
    }
    return a;
}
long long solution(int w,int h) {
    long long answer = 1;
    long long w_ = (long long)w;
    long long h_ = (long long)h;
    answer = answer = w_*h_ - (w_+h_-gcd(w_,h_));
    
    return answer;
}
