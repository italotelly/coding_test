#include <iostream>
#include <string>

using namespace std;

// 팰린드롬인지 확인하기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int check = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            check++;
        }
    }
    if (check == 0)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0; // 정상종료
}