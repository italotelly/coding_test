#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ary[1000][3]; // 색칠 비용
int dp[1000][3];  // DP 배열

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ary[i][0] >> ary[i][1] >> ary[i][2];
    }

    // 초기값 설정 (첫 번째 집은 그냥 색칠)
    dp[0][0] = ary[0][0];
    dp[0][1] = ary[0][1];
    dp[0][2] = ary[0][2];

    // DP 점화식 적용
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + ary[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + ary[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + ary[i][2];
    }

    // 마지막 집에서 최소 비용 찾기
    int result = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    cout << result << '\n';

    return 0;
}
