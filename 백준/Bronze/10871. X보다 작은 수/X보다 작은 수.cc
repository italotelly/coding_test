#include <iostream>

using namespace std;

// X보다 작은 수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;
    if (N < 1 || N > 10000 || X < 1 || X > 10000)
    {
        return 1; // 비정상 종료
    }

    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] < 1 || A[i] > 10000)
        {
            return 1; // 비정상 종료
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] < X)
        {
            cout << A[i] << " ";
        }
    }

    return 0; // 정상종료
}