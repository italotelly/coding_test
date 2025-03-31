#include <iostream>

using namespace std;

int facto(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    n = facto(n - 1) * n;

    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;

    cin >> N >> K;

    cout << facto(N) / (facto(N - K) * facto(K));

    return 0;
}