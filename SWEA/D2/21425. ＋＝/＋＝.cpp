#include <iostream>
using namespace std;

// +=
int main()
{
    int T;
    cin >> T;
    int A, B, N;
    int cnt;
    int x, y;
    // 항상 작은 수에 더해야 함.
    while (T--)
    {
        cnt = 0;
        cin >> A >> B >> N;
        x = A;
        y = B;
        while (x <= N && y <= N)
        {
            if (x <= y)
            {
                x += y;
                cnt++;
            }
            else
            {
                y += x;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
