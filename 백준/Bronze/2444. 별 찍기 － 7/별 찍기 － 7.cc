#include <iostream>
#include <iomanip>

using namespace std;

// 별 찍기 - 7
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N < 1 || N > 100)
    {
        return 1; // 비정상 종료
    }

    for (int i = 0; i < (2 * N - 1); i++)
    {
        if (i < N)
        {
            cout << setw(N - i);
            for (int j = 0; j < (2 * (i + 1) - 1); j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        else
        {
            cout << setw(i - N + 2);
            for (int j = 0; j < (2 * ((N * 2 - 1) - i) - 1); j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }

    return 0; // 정상종료
}