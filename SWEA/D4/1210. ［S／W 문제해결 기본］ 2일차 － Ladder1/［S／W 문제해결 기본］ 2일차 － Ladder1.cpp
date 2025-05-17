#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int data[100][100];

    for (int t = 1; t <= 10; ++t)
    {
        int tc;
        cin >> tc;

        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < 100; ++j)
                cin >> data[i][j];

        // 도착점(2) 위치 찾기
        int x = 99, y = 0;
        for (int j = 0; j < 100; ++j)
        {
            if (data[99][j] == 2)
            {
                y = j;
                break;
            }
        }

        // 위로 올라가기
        while (x > 0)
        {
            // 왼쪽 확인
            if (y > 0 && data[x][y - 1] == 1)
            {
                while (y > 0 && data[x][y - 1] == 1)
                    y--;
            }
            // 오른쪽 확인
            else if (y < 99 && data[x][y + 1] == 1)
            {
                while (y < 99 && data[x][y + 1] == 1)
                    y++;
            }

            // 위로 이동
            x--;
        }

        cout << "#" << tc << " " << y << "\n";
    }

    return 0;
}
