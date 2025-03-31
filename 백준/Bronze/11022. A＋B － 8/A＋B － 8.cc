#include <iostream>

using namespace std;

// A + B - 8
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    int A, B;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A < 0 || A > 10 || B < 0 || B > 10)
        {
            return 1; // 비정상 종료
        }
        cout << "Case #" << i + 1 << ": " << A << " + " << B << " = " << A + B << "\n";
    }

    return 0; // 정상종료
}