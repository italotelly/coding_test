#include <iostream>
#include <string>

using namespace std;

char ary[5][15];

// 세로읽기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++)
    {
        cin >> ary[i];
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (ary[j][i] != NULL)
            {
                cout << ary[j][i];
            }
        }
    }

    return 0; // 정상종료
}