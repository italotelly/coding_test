#include <iostream>
#include <cstdlib>

using namespace std;

// 수학은 비대면강의입니다

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 연립방정식

    int a, b, c, d, e, f;
    int x1, y1;

    cin >> a >> b >> c >> d >> e >> f;
    // 0인 수가 있다면 ,,,
    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                x1 = x;
                y1 = y;
                break;
            }
        }
    }

    cout << x1 << " " << y1;

    return 0; // 정상종료
}