#include <iostream>
#include <cmath>

using namespace std;

// 분산처리
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    int a, b;

    cin >> T;
    int num;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        a %= 10;
        num = b % 4 == 0 ? 4 : b % 4;

        int result = 1;
        for (int j = 0; j < num; j++)
        {
            result *= a;
            result %= 10;
        }

        if (result == 0)
        {
            cout << "10\n";
        }
        else
        {
            cout << result << "\n";
        }
    }

    return 0;
}