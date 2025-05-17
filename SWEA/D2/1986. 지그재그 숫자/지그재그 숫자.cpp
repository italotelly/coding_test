#include <iostream>

using namespace std;

// 지그재그 숫자
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    int num;
    int sum;
    for (int i = 1; i <= tc; i++)
    {
        cin >> num;
        sum = 0;

        for (int j = 1; j <= num; j++)
        {
            if (j % 2 == 1)
            {
                sum += j;
            }
            else
            {
                sum -= j;
            }
        }

        // 출력
        cout << "#" << i << " " << sum << "\n";
    }

    return 0;
}
