#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

// 쉬운 계단 수
int main()
{
    int N;
    cin >> N;

    // dp[i][j]: i자리 숫자에서 끝자리가 j인 경우의 개수
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    // 1자리 숫자는 1부터 9까지 가능
    for (int i = 1; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }

    // 동적 계획법으로 계산
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j - 1 >= 0)
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j + 1 <= 9)
            {
                dp[i][j] += dp[i - 1][j + 1];
            }
            dp[i][j] %= MOD;
        }
    }

    // N자리 수에서 끝자리가 0부터 9까지인 경우의 합
    long long result = 0;
    for (int i = 0; i <= 9; ++i)
    {
        result = (result + dp[N][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}
