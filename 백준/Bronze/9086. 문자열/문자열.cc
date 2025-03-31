#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// 문자열
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    if (T < 1 || T > 10)
    {
        return 1; // 비정상 종료
    }
    string S;

    for (int a = 0; a < T; a++)
    {
        cin >> S;
        if (S.size() > 1000)
        {
            return 1; // 비정상 종료
        }
        for (int i = 0; i < S.size(); i++)
        {
            if (isupper(S[i]) == 0)
            {
                return 1; // 비정상 종료
            }
        }
        cout << S.front() << S.back() << "\n";
    }
    return 0; // 정상종료
}