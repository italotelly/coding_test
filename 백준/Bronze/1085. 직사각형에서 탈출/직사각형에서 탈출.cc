#include <iostream>
#include <algorithm>

using namespace std;

// 직사각형에서 탈출
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    // w - x, y - h, w, y 중 최소값
    cout << min({w - x, h - y, x, y});

    return 0; // 정상종료
}