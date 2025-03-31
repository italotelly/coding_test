#include <iostream>

using namespace std;

// 공 바꾸기
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

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    // 공 바꾸기
    int i, j;
    int temp;
    for (int a = 0; a < M; a++)
    {
        cin >> i >> j;
        if (1 > i || i > j || j > N)
        {
            return 1; // 비정상 종료
        }
        temp = arr[i - 1];
        arr[i - 1] = arr[j - 1];
        arr[j - 1] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0; // 정상종료
}