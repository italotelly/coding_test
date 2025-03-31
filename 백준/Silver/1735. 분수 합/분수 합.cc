#include <iostream>
#include <algorithm>

using namespace std;

// 최소공배수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, D;
    int A, B;
    int a, b;
    int cnta = 1;
    int cntb = 1;

    cin >> C >> A;
    cin >> D >> B;
    a = A;
    b = B;
    while (a != b)
    {
        if (a > b)
        {
            cntb++;
            b = B * cntb;
        }
        else if (a < b)
        {
            cnta++;
            a = A * cnta;
        }
    }
    int up = C * cnta + D * cntb;
    int down = a;

    // up down의 최대공약수
    int k = __gcd(up, down);

    cout << up / k << " " << down / k;

    return 0;
}