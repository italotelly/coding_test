#include <iostream>

using namespace std;

int dp[21][21][21]; // 메모이제이션용 배열

// w 함수 정의
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1; // 기저 사례
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20); // 20 초과는 20으로 변환

    if (dp[a][b][c] != 0)
        return dp[a][b][c]; // 이미 계산된 값이면 반환

    // 점화식 적용
    if (a < b && b < c)
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return dp[a][b][c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break; // 종료 조건

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}
