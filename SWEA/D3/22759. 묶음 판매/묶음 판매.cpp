#include <iostream>
using namespace std;

// 묶음 판매
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long L, R;
        cin >> L >> R;

        if (R < 2 * L)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
