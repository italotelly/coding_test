#include <iostream>
#include <string>

using namespace std;

int recursion(const string &s, int l, int r, int &cnt) {
    cnt++;
    if (l >= r) return 1;
    if (s[l] != s[r]) return 0;
    return recursion(s, l + 1, r - 1, cnt);
}

int isPalindrome(const string &s, int &cnt) {
    return recursion(s, 0, s.size() - 1, cnt);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        int cnt = 0;
        cout << isPalindrome(S, cnt) << " " << cnt << "\n";
    }
    return 0;
}
