#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    // 왼쪽에 큰게 존재하는가
    vector<bool> lcheck(a.size());
    // 오른쪽에 큰게 존재하는가
    vector<bool> rcheck(a.size());
    
    int Lmin = 1000000005;
    int Rmin = 1000000005;
    for(int i=0; i<a.size(); i++){
        //왼쪽 탐색
        if(a[i]>Lmin){
           //왼쪽에 더 작은 숫자가 존재 -> 작은 수 폭파 한번 필요
            lcheck[i] = true;
        }
        Lmin = a[i] <=Lmin ? a[i] : Lmin;
    }
    for(int i= a.size()-1; i>=0; i--){
        if(a[i]>Rmin){
            //오른쪽에 더 작은 숫자가 존재 -> 작은 수 폭파 한번 필요
            rcheck[i] = true;
        }
        Rmin = a[i]<= Rmin ? a[i] : Rmin;
    }
    vector<int> test;
    for(int i=0; i<a.size(); i++){
        if(!(lcheck[i] & rcheck[i])){
            // 둘 다 true 일 경우는 폭파 2번 필요하다는 뜻
            test.push_back(a[i]);
            answer++;
        }
    }
    /*
    for(auto item : test){
        cout<<item<<" ";
    }
    */
    return answer;
}
