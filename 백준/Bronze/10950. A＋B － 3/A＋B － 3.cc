#include <iostream>

using namespace std;

int main()
{
    int T; // test case
    cin >> T;

    int A, B;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;

        if (A <= 0 || A >= 10 || B <= 0 || B >= 10)
        {
            return 1; // 비정상 종료
        }

        cout << A + B << endl;
    }

    return 0; // 정상종료
}