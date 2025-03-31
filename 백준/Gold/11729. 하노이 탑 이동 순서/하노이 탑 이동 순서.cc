#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        cout << a << " " << c << "\n";
    }
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << " " << c << "\n";
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int K = pow(2, N) - 1;
    cout << K << "\n";
    hanoi(N, 1, 2, 3);

    return 0;
}