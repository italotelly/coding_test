#include <iostream>
#include <vector>

using namespace std;

// 그룹 단어 체커
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> word;

    int groupchecker = 0;
    int notgroupchecker = 0;

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        word.push_back(a);

        notgroupchecker = 0;

        if (a.size() < 3)
        {
            groupchecker++;
        }
        else
        {
            for (int j = 0; j < a.size() - 1; j++)
            {
                if (a[j] == a[j + 1])
                {
                    if (j == (a.size() - 2))
                    {
                        continue;
                    }
                }
                else
                {
                    for (int k = 0; (j + k + 2) < a.size(); k++)
                    {
                        if (a[j] == a[j + k + 2])
                        {
                            notgroupchecker = 1;
                            break;
                        }
                    }
                    if (notgroupchecker == 1)
                    {
                        break;
                    }
                }
            }
            if (notgroupchecker != 1)
            {
                groupchecker++;
            }
        }
    }

    cout << groupchecker;

    return 0; // 정상종료
}