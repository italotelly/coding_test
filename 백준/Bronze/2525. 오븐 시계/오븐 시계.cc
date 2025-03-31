#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    if (A > 23 || A < 0 || B < 0 || B > 59 || C < 0 || C > 1000)
        return 0;

    /* 오븐 시계
    현재 시각, A (0 ≤ A ≤ 23), B (0 ≤ B ≤ 59)
    요리하는데 필요한 시간 C (0 ≤ C ≤ 1,000)
    if문을 나눠야 하는데

    - B + C 가 % 60가 0이고 / 60 1 ~ 17 인 경우
    - A가 23이고 B + C 가 >= 60 경우
    */
    int D = 0;

    if ((B + C) >= 60)
    {
        D = ((B + C) / 60);

        if (A + D > 23)
        {
            cout << A + D - 24 << " " << B + C - 60 * D;
        }
        else
            cout << A + D << " " << B + C - 60 * D;
    }
    else
        cout << A << " " << B + C - 60 * D;
}