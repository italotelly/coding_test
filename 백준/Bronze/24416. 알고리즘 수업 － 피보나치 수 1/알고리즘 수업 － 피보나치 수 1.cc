#include <iostream>

using namespace std;

int f[40];

// 재귀
int fib(int n, int &cnt)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        cnt++;
        return fib(n - 1, cnt) + fib(n - 2, cnt);
    }
}

// DP
int fibonacci(int n, int &cnt)
{
    f[1] = 1;
    f[2] = 1;

    for (int i = 3; i < n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        cnt++;
    }
    return f[n];
}

int main()
{
    int n;
    int cnt1 = 1;
    int cnt2 = 1;
    cin >> n;

    fib(n, cnt1);
    fibonacci(n, cnt2);

    cout << cnt1 << " " << cnt2;
}