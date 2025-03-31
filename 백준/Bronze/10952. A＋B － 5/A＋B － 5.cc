#include <iostream>
#include <iomanip>

using namespace std;

// A + B - 5
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B;

    while (true)
    {
        cin >> A >> B;
        if (A < 0 || A >= 10 || B < 0 || B >= 10)
        {
            return 1; // 비정상 종료
        }
        if (A == 0 && B == 0)
        {
            break;
        }
        cout << A + B << "\n";
    }

    return 0; // 정상종료
}