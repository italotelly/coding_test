#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// 단어 공부
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    vector<char> word;
    vector<int> word_cnt;
    word.push_back(s[0]);
    word_cnt.push_back(1);

    // 단어 개수 세기
    for (int i = 0; i < s.size(); i++)
    {
        int n = 0;
        for (int j = 0; j < word.size(); j++)
        {
            if (word[j] == s[i + 1])
            {
                word_cnt[j] += 1;
                n = 1;
            }
        }
        if (i == s.size() - 1)
        {
            n = 1;
        }
        if (n == 0)
        {
            word.push_back(s[i + 1]);
            word_cnt.push_back(1);
        }
    }

    // 가장 많이 사용된 알파벳 출력
    int most_num = 0;
    for (int i = 0; i < word_cnt.size() - 1; i++)
    {
        if (word_cnt[most_num] < word_cnt[i + 1])
        {
            most_num = i + 1;
        }
    }

    // 가장 많이 사용된 알파벳이 여러 개 존재하는 경우 ? 출력
    int qmark = 0;
    for (int i = 0; i < word_cnt.size(); i++)
    {
        if (most_num == i)
        {
            continue;
        }
        if (word_cnt[most_num] == word_cnt[i])
        {
            qmark = 1;
        }
    }

    // 마지막 출력
    if (qmark == 1)
    {
        cout << "?";
    }
    else
    {
        cout << word[most_num];
    }

    /* validation
    cout << "\n";
    for (int i = 0; i < word_cnt.size(); i++)
    {
        cout << word[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < word_cnt.size(); i++)
    {
        cout << word_cnt[i] << " ";
    }*/

    return 0; // 정상종료
}