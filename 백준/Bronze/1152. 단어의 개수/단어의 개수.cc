#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 단어의 개수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string S;
    getline(cin, S);
    if (S.size() > 1000000)
    {
        return 1; // 비정상 종료
    }
    int word_str = 0;
    int word_cnt = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != ' ')
        {
            word_str = 1;
        }
        if (((word_str == 1) && (S[i] == ' ')) || (word_str == 1) && (i + 1 == S.size()))
        {
            word_cnt += 1;
            word_str = 0;
        }
    }
    cout << word_cnt;

    return 0; // 정상종료
}