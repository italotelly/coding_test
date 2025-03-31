#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// 문자와 문자열
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;

    cin >> S;
    if (S.size() > 100)
    {
        return 1; // 비정상 종료
    }
    // 대문자 혹은 소문자로만 이루어진 단어
    for (int i = 0; i < S.size(); i++)
    {
        if (isupper(S[0]) != 0)
        {
            if (isupper(S[i] == 0))
            {
                return 1; // 비정상 종료
            }
        }
        else
        {
            if (islower(S[i] == 0))
            {
                return 1; // 비정상 종료
            }
        }
    }

    cout << S.size();

    return 0; // 정상종료
}