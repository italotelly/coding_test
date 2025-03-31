#include <iostream>
#include <algorithm>

using namespace std;

// 최댓값
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A[9];
    for (int i = 0; i < 9; i++)
    {
        cin >> A[i];
        if (A[i] < 0)
        {
            return 1; // 비정상 종료
        }
    }

    int max = 0;
    int max_num = 0;

    for (int i = 0; i < 9; i++)
    {
        if (max < A[i])
        {
            max = A[i];
            max_num = i + 1;
        }
    }

    cout << max << "\n"
         << max_num;

    return 0; // 정상종료
}