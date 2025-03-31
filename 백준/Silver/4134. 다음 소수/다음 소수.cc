#include <iostream>

using namespace std;

// 다음 소수

// 소수 판별 함수 (√n까지만 검사)
bool is_prime(long long n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true; // 2는 유일한 짝수 소수
    if (n % 2 == 0)
        return false; // 짝수는 소수가 아님

    for (long long i = 3; i * i <= n; i += 2) // 3부터 √n까지만 검사 (홀수만)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        // 2 이하일 경우 예외 처리
        if (n <= 2)
        {
            cout << "2\n";
            continue;
        }

        // 짝수라면 홀수로 변경
        if (n % 2 == 0)
            n++;

        // 다음 소수 찾기
        while (!is_prime(n))
            n += 2; // 홀수만 검사하여 연산 절반 감소

        cout << n << "\n";
    }

    return 0;
}