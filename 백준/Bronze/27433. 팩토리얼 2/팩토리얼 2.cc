#include <iostream>

using namespace std;

long long int facto(int N)
{
    if (N <= 1)
    {
        return 1;
    }
    return N * facto(N - 1);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    cout << facto(N);
    return 0;
}