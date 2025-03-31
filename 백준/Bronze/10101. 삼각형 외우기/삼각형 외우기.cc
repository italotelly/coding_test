#include <iostream>

using namespace std;

// 삼각형 외우기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x, y, z;

    cin >> x >> y >> z;

    if (x == 60 && y == 60 && z == 60)
    {
        cout << "Equilateral";
    }

    else if (x + y + z == 180)
    {
        if (x == y || y == z || x == z)
        {
            cout << "Isosceles";
        }
        else
            cout << "Scalene";
    }

    else
        cout << "Error";

    return 0; // 정상종료
}