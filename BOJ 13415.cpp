#include <stdio.h>
#include <deque>
#include <algorithm>
 
using namespace std;
const int MAX = 100001;
int n, arr[MAX], final_arr[MAX], k, sort_idx;
deque<int> set;
 
int main() {
    //입력
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    
    //스택처럼 사용 최근에 나보다 작은 값들을 제거 후 추가
    for (int i = 0; i < k; i++) {
        int asc, desc;
        scanf("%d %d", &asc, &desc);
        sort_idx = max(sort_idx, max(asc, desc));
        while (!set.empty() && abs(set.back()) <= asc) set.pop_back();
        set.push_back(asc);
        while (!set.empty() && abs(set.back()) <= desc) set.pop_back();
        set.push_back(-desc);
    }
    //마지막 연산 위해
    set.push_back(0);
    //최대범위내로 정렬
    sort(arr + 1, arr + sort_idx + 1);
    //초기값
    int final_idx = sort_idx;
    int asc_idx = sort_idx;
    int desc_idx = 1;
    //정렬시작
    int cur = set.front();
    set.pop_front();
    while (!set.empty()) {
        int next = set.front();
        set.pop_front();
        //차이만큼 final_arr에 대입
        int len = abs(cur) - abs(next);
        //오름차순명령일때
        if (cur > 0) {
            for (int i = 0; i < len; i++) {
                final_arr[final_idx--] = arr[asc_idx--];
            }
        }
        //내림차순 명령일때
        else {
            for (int i = 0; i < len; i++) {
                final_arr[final_idx--] = arr[desc_idx++];
            }
        }
        cur = next;
    }
    //새로운 배열 출력
    for (int i = 1; i <= sort_idx; i++) {
        printf("%d ", final_arr[i]);
    }
    //명령에 무관한 배열 
    for (int i = sort_idx + 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
