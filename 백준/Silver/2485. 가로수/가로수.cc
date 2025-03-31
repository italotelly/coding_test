#include <iostream>
#include <algorithm>

using namespace std;

// 가로수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    int ary[N] = {0};
    int minus[N - 1] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> ary[i];
    }
    int gcd_value = ary[1] - ary[0];
    for (int i = 2; i < N; i++)
    {
        gcd_value = __gcd(gcd_value, ary[i] - ary[i - 1]);
    }

    int j = 0;
    int cnt = 0;
    int number = ary[0];
    while (j < N)
    {
        if (ary[j] == number)
        {
            number += gcd_value;
            j++;
        }
        else
        {
            cnt++;
            number += gcd_value;
        }
    }

    cout << cnt;

    return 0;
}