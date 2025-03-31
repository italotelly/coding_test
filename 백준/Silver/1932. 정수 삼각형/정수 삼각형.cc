#include <iostream>
#include <algorithm>

using namespace std;

int ary[125250];
int dp[125250];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int num;
    int max_num = 0;
    for (int i = 0; i < (n * (n + 1) / 2); i++)
    {
        cin >> num;
        ary[i] = num;
    }

    if (n == 1)
    {
        cout << ary[0];
        return 0;
    }

    dp[0] = ary[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                dp[(i * (i + 1)) / 2] = dp[((i - 1) * i) / 2] + ary[(i * (i + 1)) / 2];
            }
            else if (j == i)
            {
                dp[(i * (i + 1)) / 2 + i] = dp[((i - 1) * i) / 2 + i - 1] + ary[(i * (i + 1)) / 2 + i];
            }
            else
            {
                dp[(i * (i + 1)) / 2 + j] = max(dp[((i - 1) * i) / 2 + (j - 1)], dp[((i - 1) * i) / 2 + j]) + ary[(i * (i + 1)) / 2 + j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        max_num = max(max_num, dp[(n - 1) * n / 2 + i]);
    }
    cout << max_num;

    return 0;
}