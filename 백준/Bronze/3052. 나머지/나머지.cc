#include <iostream>

using namespace std;

// 나머지
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[10] = {};
    int n;

    for (int i = 0; i < 10; i++)
    {

        cin >> n;
        if (n < 0 || n > 1000)
        {
            return 1; // 비정상 종료
        }
        arr[i] = n % 42;
    }
    int count = 10;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[j] == -1)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                count--;
                arr[j] = -1;
            }
        }
    }

    cout << count;
    return 0; // 정상종료
}