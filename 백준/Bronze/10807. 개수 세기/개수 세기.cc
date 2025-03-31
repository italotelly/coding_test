#include <iostream>

using namespace std;

// 개수 세기기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N < 1 || N > 100)
    {
        return 1; // 비정상 종료
    }

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int v;
    cin >> v;
    if (v < -100 || v > 100)
    {
        return 1; // 비정상 종료
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == v)
        {
            count++;
        }
    }

    cout << count;

    return 0; // 정상종료
}