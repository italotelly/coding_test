#include <iostream>

using namespace std;

// 소수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int M, N;
    cin >> M >> N;
    // M이상 N이하의 자연수 중 소수인 것을 골라 이들 소수의 합과 최솟값

    int first_num = 0;
    int first = 0;
    int p_number = 0;
    int sum = 0;
    for (int i = M; i <= N; i++)
    {
        p_number = 0;
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                if (i == j)
                {
                    first_num++;
                    sum += i;
                    if (first_num == 1)
                    {
                        first = i;
                    }
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        if (p_number == 1)
        {
            sum += i;
        }
    }

    if (sum > 0)
    {
        cout << sum << "\n"
             << first;
    }
    else
        cout << "-1";

    return 0; // 정상종료
}