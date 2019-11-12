#include <string>
#include <vector>
using namespace std;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(string now : phone_book){
        for(string prev : phone_book){
            if(now!=prev){ //내가 나를 보는 경우 생략하기
                if(now.length()>prev.length()){
                    if(prev==now.substr(0, prev.length())){
                        return false;
                    }
                }
            }
        }
    }
    return answer;
}
