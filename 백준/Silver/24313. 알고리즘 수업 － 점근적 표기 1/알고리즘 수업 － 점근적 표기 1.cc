#include <iostream>

using namespace std;

// 알고리즘 수업 - 점근적 표기 1

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a1, a0;
    cin >> a1 >> a0;

    int c;
    cin >> c;

    int n0;
    cin >> n0;

    int cnt = 0;
    for (int i = n0; i <= 100; i++)
    {
        if ((a1 * i + a0) <= c * i)
        {
            cnt++;
        }
    }

    if (cnt == (100 - n0 + 1))
        cout << "1";
    else
        cout << "0";
    return 0; // 정상종료
}