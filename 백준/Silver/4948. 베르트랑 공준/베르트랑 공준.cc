#include <iostream>

using namespace std;

// 베르트랑 공준

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 1;

    while (true)
    {
        cin >> num;
        if (num == 0)
        {
            break;
        }
        int primary = 0;
        for (int i = num + 1; i <= 2 * num; i++)
        {
            int cnt = 0;
            if (i == 1)
            {
                continue;
            }
            if (i == 2)
            {
                primary++;
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
                primary++;
            }
        }
        cout << primary << "\n";
    }
    return 0;
}