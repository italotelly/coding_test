#include <iostream>

using namespace std;

// 소인수 분해
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            if (N == 1)
            {
                break;
            }

            else
            {
                N = N / i;
                cout << i << "\n";
                i = 1;
            }
        }
    }

    return 0; // 정상종료
}