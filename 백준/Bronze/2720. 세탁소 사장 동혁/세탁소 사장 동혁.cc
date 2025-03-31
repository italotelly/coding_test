#include <iostream>

using namespace std;

// 세탁소 사장 동혁
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 0.25 0.10 0.05 0.01
    // 거스름돈은 항상 5달러 이하, 손님이 받는 동전 개수를 최소화
    // 거스름돈 배열
    double ary[] = {25, 10, 5, 1};

    int T;
    cin >> T;

    double charge;
    for (int i = 0; i < T; i++)
    {
        cin >> charge;
        if ((charge / ary[0]) >= 1)
        {
            cout << (int)(charge / ary[0]) << " ";
            charge = charge - ary[0] * (int)(charge / ary[0]);
        }
        else
        {
            cout << "0 ";
        }
        if ((charge / ary[1]) >= 1)
        {
            cout << (int)(charge / ary[1]) << " ";
            charge = charge - ary[1] * (int)(charge / ary[1]);
        }
        else
        {
            cout << "0 ";
        }
        if ((charge / ary[2]) >= 1)
        {
            cout << (int)(charge / ary[2]) << " ";
            charge = charge - ary[2] * (int)(charge / ary[2]);
        }
        else
        {
            cout << "0 ";
        }
        if ((charge / ary[3]) >= 1)
        {
            cout << (int)(charge / ary[3]) << " ";
            charge = charge - ary[3] * (int)(charge / ary[3]);
        }
        else
        {
            cout << "0 ";
        }
        cout << "\n";
    }

    return 0; // 정상종료
}