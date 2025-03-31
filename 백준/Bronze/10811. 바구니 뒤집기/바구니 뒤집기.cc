#include <iostream>

using namespace std;

// 바구니 뒤집기기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    if (N < 1 || N > 100 || M < 1 || M > 100)
    {
        return 1; // 비정상 종료
    }

    int arr[N] = {};
    for (int a = 0; a < N; a++)
    {
        arr[a] = a + 1;
    }
    int i, j;
    for (int b = 0; b < M; b++)
    {
        cin >> i >> j;
        if (1 > i || i > j || j > N)
        {
            return 1; // 비정상 종료
        }
        for (int c = 0; c < ((j - i + 1) / 2); c++)
        {
            int temp = 0;
            temp = arr[j - c - 1];
            arr[j - c - 1] = arr[i + c - 1];
            arr[i + c - 1] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0; // 정상종료
}