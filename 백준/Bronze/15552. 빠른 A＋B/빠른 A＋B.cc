#include <iostream>

using namespace std;

// 빠른 A + B
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    if (T > 1000000)
    {
        return 1; // 비정상 종료
    }

    int A, B;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A < 1 || A > 1000 || B < 1 || B > 1000)
        {
            return 1; // 비정상 종료
        }
        cout << A + B << "\n";
    }

    return 0; // 정상종료
}