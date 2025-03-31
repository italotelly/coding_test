#include <iostream>
#include <cmath>

using namespace std;

// 중앙 이동 알고리즘
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 점 개수 출력

    int N;
    int pnum = 4;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        pnum = pow(((sqrt(pnum) * 2) - 1), 2);
    }

    cout << pnum;

    return 0; // 정상종료
}