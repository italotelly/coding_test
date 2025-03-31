#include <iostream>
#include <algorithm>

using namespace std;

// 최소, 최대
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N < 1 || N > 1000000)
    {
        return 1; // 비정상 종료
    }

    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] < -1000000 || A[i] > 1000000)
        {
            return 1; // 비정상 종료
        }
    }

    cout << *min_element(A, A + N) << " " << *max_element(A, A + N);

    return 0; // 정상종료
}