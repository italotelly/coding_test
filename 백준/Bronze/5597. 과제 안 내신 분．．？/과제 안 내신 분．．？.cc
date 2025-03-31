#include <iostream>

using namespace std;

// 과제 안 내신분
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[30] = {};

    int n = 0;

    for (int i = 0; i < 28; i++)
    {

        cin >> n;
        if (n < 1 || n > 30)
        {
            return 1; // 비정상 종료
        }

        arr[n - 1] += 1;
    }

    int arr2[2] = {};
    int a = 0;
    for (int i = 0; i < 30; i++)
    {
        if (arr[i] == 0)
        {
            arr2[a] = i + 1;
            a++;
        }
    }

    if (arr2[0] < arr2[1])
    {
        cout << arr2[0] << "\n"
             << arr2[1];
    }
    else
    {
        cout << arr2[1] << "\n"
             << arr2[0];
    }

    return 0; // 정상종료
}