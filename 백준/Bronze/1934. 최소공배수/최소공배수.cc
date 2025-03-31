#include <iostream>

using namespace std;

// 최소공배수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    int A, B;
    int a, b;
    int cnta = 2;
    int cntb = 2;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cnta = 2;
        cntb = 2;
        a = A;
        b = B;
        while (a != b)
        {
            if (a > b)
            {
                b = B * cntb;
                cntb++;
            }
            else if (a < b)
            {
                a = A * cnta;
                cnta++;
            }
        }
        cout << a << "\n";
    }

    return 0;
}