#include <iostream>

using namespace std;

// 최댓값
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int ary[9][9] = {0};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> ary[i][j];
        }
    }

    int max = -1;
    int max_pos[2] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (max < ary[i][j])
            {
                max = ary[i][j];
                max_pos[0] = i + 1;
                max_pos[1] = j + 1;
            }
        }
    }

    cout << max << "\n"
         << max_pos[0] << " " << max_pos[1];

    return 0; // 정상종료
}