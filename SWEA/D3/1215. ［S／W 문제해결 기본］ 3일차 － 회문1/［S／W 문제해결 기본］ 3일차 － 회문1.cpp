#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; ++tc) {
        int N;
        cin >> N;

        vector<string> board(8);
        for (int i = 0; i < 8; ++i)
            cin >> board[i];

        int cnt = 0;

        // 가로 검사
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j <= 8 - N; ++j) {
                string row = board[i].substr(j, N);
                if (isPalindrome(row)) cnt++;
            }
        }

        // 세로 검사
        for (int j = 0; j < 8; ++j) {
            for (int i = 0; i <= 8 - N; ++i) {
                string col = "";
                for (int k = 0; k < N; ++k)
                    col += board[i + k][j];
                if (isPalindrome(col)) cnt++;
            }
        }

        cout << "#" << tc << " " << cnt << "\n";
    }

    return 0;
}
