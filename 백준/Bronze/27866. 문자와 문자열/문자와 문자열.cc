#include <iostream>
#include <string>

using namespace std;

// 문자와 문자열
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;
    int i;

    cin >> S;
    if (S.size() > 1000)
    {
        return 1; // 비정상 종료
    }

    cin >> i;
    if (i < 1 || i > S.size())
    {
        return 1; // 비정상 종료
    }

    cout << S[i - 1];

    return 0; // 정상종료
}