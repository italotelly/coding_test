#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 알파벳 찾기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    if (S.size() > 100)
    {
        return 1; // 비정상 출력
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (islower(S[i]) == 0)
        {
            return 1; // 비정상 출력
        }
    }

    int position = -1;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < S.size(); j++)
        {
            if ((i + 97) == (int)S[j])
            {
                position = j;
                break;
            }
            else
            {
                position = -1;
            }
        }
        cout << position << " ";
    }

    return 0; // 정상종료
}