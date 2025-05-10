#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        int pos1 = 0, maxDist1 = 0; // '?'를 모두 R로 처리
        int pos2 = 0, maxDist2 = 0; // '?'를 모두 L로 처리

        for (char c : S) {
            if (c == 'L') {
                pos1--;
                pos2--;
            } else if (c == 'R') {
                pos1++;
                pos2++;
            } else { // '?'
                pos1++;  // R로 간주
                pos2--;  // L로 간주
            }

            // 공통: 이동 후 현재까지의 최대 거리 갱신
            maxDist1 = max(maxDist1, abs(pos1));
            maxDist2 = max(maxDist2, abs(pos2));
        }

        cout << max(maxDist1, maxDist2) << '\n';
    }

    return 0;
}
