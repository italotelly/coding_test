#include <iostream>

using namespace std;

// 분수찾기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 오른쪽 이동 1, 2,       7,                                    16
    // 1.1 -> 1.2 ... -> 1.4
    // 왼쪽 대각선 이동 3,       8, 9, 10
    // -> 2.1
    // 아래로 이동         4,              11
    // -> 3.1
    // 오른쪽 대각선 이동      5, 6,                12, 13, 14, 15
    // -> 2.2 -> 1.3

    // 1 2 6 7 15 16 28 29
    //    4   8     12

    // 3 4 10 11 21
    //   4+2   8+2

    int X;
    int a = 1;
    int b = 1;
    int count = 1;
    int layer = 1;
    int move;
    int swap = 0;
    cin >> X;

    while (X > count)
    {
        count += (layer * 4 + 1);
        layer++;
        b += 2;
    }
    move = count;
    while (X != move)
    {
        if (move == count - ((layer - 1) * 2))
        {
            a--;
            move--;
            swap = 1;
            continue;
        }
        if (swap == 0)
        {
            b--;
            a++;
            move--;
        }
        else if (swap == 1)
        {
            b++;
            a--;
            move--;
        }
    }
    cout << a << "/" << b;

    return 0; // 정상종료
}