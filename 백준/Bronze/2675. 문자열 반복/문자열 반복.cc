#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 문자열 반복
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    if (T < 1 || T > 1000)
    {
        return 1; // 비정상 종료
    }

    int R;
    string S;
    for (int i = 0; i < T; i++)
    {
        cin >> R;
        if (R < 1 || R > 8)
        {
            return 1; // 비정상 종료
        }
        cin >> S;
        for (int j = 0; j < S.size(); j++)
        {
            for (int k = 0; k < R; k++)
            {
                cout << S[j];
            }
        }
        cout << "\n";
    }

    return 0; // 정상종료
}