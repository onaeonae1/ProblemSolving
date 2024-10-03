#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
int main() {
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(false);
    string word, exp, ans;
    stack<char> inspect;
    cin >> word >> exp;
    for (char c : word) {
        inspect.push(c);
        if (c == exp.back() && inspect.size() >= exp.length()) {
            string t;
            for (char e : exp) {
                t.push_back(inspect.top());
                inspect.pop();
            }
            reverse(t.begin(), t.end()); // 스택 뒤집기
            if (t.compare(exp) != 0) {
                for (char tt : t) {
                    inspect.push(tt);
                }
            }
        }
    }
    // stack push
    while (!inspect.empty()) {
        ans.push_back(inspect.top());
        inspect.pop();
    }
    if (ans.empty()) {
        cout << "FRULA" ;
    }
    else {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    }
    return 0;
}
