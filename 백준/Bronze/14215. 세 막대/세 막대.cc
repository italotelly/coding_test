#include <iostream>

using namespace std;

// 세 막대
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b, c;

    cin >> a >> b >> c;

    int m, left;

    m = max(max(a, b), c);
    if (m == a)
    {
        left = b + c;
    }
    else if (m == b)
    {
        left = a + c;
    }
    else
    {
        left = a + b;
    }

    if (m >= left)
    {
        while (m >= left)
        {
            m--;
        }
    }

    else
    {
        m = a;
        left = b + c;
    }

    cout << m + left;

    return 0; // 정상종료
}