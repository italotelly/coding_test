#include <iostream>

using namespace std;

// 영수증 문제제
int main()
{
    int X, N;
    cin >> X >> N;

    if (X < 1 || X > 1000000000 || N < 1 || N > 100)
    {
        return 1; // 비정상 종료
    }

    int a, b;
    int total = 0;
    // a < 1 || a > 1000000 || b < 1 || b > 10
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        if (a < 1 || a > 1000000 || b < 1 || b > 10)
        {
            return 1; // 비정상 종료
        }

        total += a * b;
    }

    if (X == total)
        cout << "Yes";
    else
        cout << "No";

    return 0; // 정상종료
}