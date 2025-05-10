#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;

        int pos1 = 0, maxDist1 = 0; // case 1: '?' 전부 R
        int pos2 = 0, maxDist2 = 0; // case 2: '?' 전부 L

        for (char c : S)
        {
            if (c == 'L')
                pos1--, pos2--;
            else if (c == 'R')
                pos1++, pos2++;
            else
            {
                // '?'를 R로 간주한 경우
                pos1++;
                maxDist1 = max(maxDist1, abs(pos1));

                // '?'를 L로 간주한 경우
                pos2--;
                maxDist2 = max(maxDist2, abs(pos2));
                continue;
            }

            maxDist1 = max(maxDist1, abs(pos1));
            maxDist2 = max(maxDist2, abs(pos2));
        }

        // 최댓값 출력
        cout << max(maxDist1, maxDist2) << '\n';
    }

    return 0;
}
