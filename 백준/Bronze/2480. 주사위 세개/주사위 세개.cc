#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    if (A > 6 || A < 1 || B > 6 || B < 1 || C > 6 || C < 1)
        return 1; // 비정상 종료

    /* 주사위 세개
    ABC 범위 1 ~ 6

    1. 같은 눈 3개 10000 + 눈 크기 * 1000
    2. 같은 눈 2개 1000 + 눈 크기 * 100
    3. 모두 다른 눈 그 중 가장 큰 눈 * 100

    */
    // 1, 연속 등호가 안됨
    if (A == B && B == C)
    {
        cout << 10000 + A * 1000;
    }

    // 2,
    else if (A == B || B == C)
    {
        cout << 1000 + B * 100;
    }
    else if (A == C)
    {
        cout << 1000 + A * 100;
    }
    else
    {
        cout << max({A, B, C}) * 100;
    }

    return 0; // 정상종료
}