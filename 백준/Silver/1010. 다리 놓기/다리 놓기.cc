#include <iostream>

using namespace std;

long long combi(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        cout << combi(M, N) << "\n";
    }

    return 0;
}
