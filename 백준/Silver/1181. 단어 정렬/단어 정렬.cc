#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 단어 정렬

bool compare(string a, string b)
{
    if (a.size() == b.size())
    {
        int i = 0;
        while (i < a.size())
        {
            if (int(a[i]) == int(b[i]))
            {
                i++;
            }
            else
            {
                break;
            }
        }
        return int(a[i]) < int(b[i]);
    }
    else
    {
        return a.size() < b.size();
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    string words[N];
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    sort(words, words + N, compare);

    for (int i = 0; i < N; i++)
    {
        if (words[i] == words[i - 1])
        {
            continue;
        }
        else
        {
            cout << words[i] << "\n";
        }
    }

    return 0;
}