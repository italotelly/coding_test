#include <iostream>
#include <cmath>

using namespace std;

// 대지
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    int x, y;
    int x_max = -10000;
    int y_max = -10000;
    int x_min = 10000;
    int y_min = 10000;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;

        if (N == 1)
        {
            cout << "0";
            return 0;
        }

        if (x > x_max)
        {
            x_max = x;
        }
        if (x < x_min)
        {
            x_min = x;
        }

        if (y > y_max)
        {
            y_max = y;
        }
        if (y < y_min)
        {
            y_min = y;
        }
    }

    cout << (x_max - x_min) * (y_max - y_min);

    return 0; // 정상종료
}