#include <iostream>
#include <algorithm>

using namespace std;

int ary[301]; // 계단 점수
int dp[301];  // 최대 점수 DP 배열

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> ary[i];
    }

    // 초기값 설정
    dp[1] = ary[1];
    if (n >= 2)
        dp[2] = ary[1] + ary[2];
    if (n >= 3)
        dp[3] = max(ary[1], ary[2]) + ary[3];

    // DP 점화식 적용
    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + ary[i - 1]) + ary[i];
    }

    cout << dp[n] << '\n';
    return 0;
}
