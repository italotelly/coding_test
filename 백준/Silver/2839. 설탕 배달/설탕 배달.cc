#include <iostream>

using namespace std;

// 설탕 배달

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 3키로 봉지와 5키로 봉지

    int N;

    cin >> N;

    // 3x + 5y = N
    // x + y를 출력
    // x + y의 최솟값

    int x = 0;
    int y = 0;
    int cnt = 1667;

    for (int y = 0; (3 * x + 5 * y) <= N; y++)
    {
        for (int x = 0; (3 * x + 5 * y) <= N; x++)
        {
            if ((3 * x + 5 * y) == N)
            {
                if (cnt > x + y)
                {
                    cnt = x + y;
                }
            }
        }
    }
    if (cnt == 1667)
        cout << "-1";
    else
        cout << cnt;

    return 0; // 정상종료
}