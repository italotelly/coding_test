#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];  // dp[i] = i를 1로 만들기 위한 최소 연산 횟수

int main() {
    int N;
    cin >> N;

    dp[1] = 0;  // 1은 이미 1이므로 연산이 필요 없음

    for (int i = 2; i <= N; i++) {
        // 기본적으로 i-1을 하는 경우
        dp[i] = dp[i - 1] + 1;

        // 2로 나누어떨어지는 경우
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        // 3으로 나누어떨어지는 경우
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[N] << '\n';
    return 0;
}
