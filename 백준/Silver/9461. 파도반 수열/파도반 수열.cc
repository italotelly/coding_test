#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int ary[100];

long long int tri(int n)
{
    ary[1] = 1;
    ary[2] = 1;
    ary[3] = 2;
    for (int i = 3; i <= n; i++)
    {
        ary[i] = (ary[i - 2] + ary[i - 3]);
    }
    return ary[n];
}

// 파도반 수열
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    int num;
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        cout << tri(num) << "\n";
    }

    return 0; // 정상종료
}