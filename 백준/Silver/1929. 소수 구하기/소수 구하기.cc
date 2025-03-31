#include <iostream>

using namespace std;

// 소수 구하기

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;

    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        int cnt = 0;
        if (i == 1)
        {
            continue;
        }
        if (i == 2)
        {
            cout << "2\n";
            continue;
        }
        if (i % 2 == 0)
        {
            continue;
        }
        for (int j = 3; j * j <= i; j += 2)
        {
            if (i % j == 0)
            {
                cnt++;
                break;
            }
        }
        if (cnt == 0)
        {
            cout << i << "\n";
        }
    }

    return 0;
}