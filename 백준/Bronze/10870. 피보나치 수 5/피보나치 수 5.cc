#include <iostream>

using namespace std;

int fibo(int N)
{
    if (N == 0)
    {
        return 0;
    }
    else if (N == 1)
    {
        return 1;
    }
    return (fibo(N - 1) + fibo(N - 2));
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    cout << fibo(N);
    return 0;
}