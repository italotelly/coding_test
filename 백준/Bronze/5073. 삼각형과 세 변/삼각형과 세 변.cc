#include <iostream>

using namespace std;

// 삼각형과 세 변
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x, y, z;
    int m;
    int left;

    while (true)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }

        if (x == y && y == z)
        {
            cout << "Equilateral\n";
        }
        else
        {
            m = max(max(x, y), z);
            if (m == x)
            {
                left = y + z;
            }
            else if (m == y)
            {
                left = x + z;
            }
            else
            {
                left = x + y;
            }
            if (m >= left)
            {
                cout << "Invalid\n";
            }
            else if (x == y || y == z || x == z)
            {
                cout << "Isosceles\n";
            }
            else
            {
                cout << "Scalene\n";
            }
        }
    }
    return 0; // 정상종료
}