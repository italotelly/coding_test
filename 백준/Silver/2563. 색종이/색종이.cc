#include <iostream>

using namespace std;

// 색종이
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 가로 세로 크기가 100인 정사각형 흰색 도화지
    int base[100][100] = {0};

    int number;
    // 색종이 개수
    cin >> number;

    int ary[number][2];
    for (int i = 0; i < number; i++)
    {
        cin >> ary[i][0] >> ary[i][1];
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = ary[i][0]; (j >= ary[i][0]) && (j < (ary[i][0] + 10)); j++)
        {
            for (int k = ary[i][1]; (k >= ary[i][1]) && (k < (ary[i][1] + 10)); k++)
            {
                base[j][k] += 1;
            }
        }
    }

    int area = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (base[i][j] >= 2)
            {
                area += (base[i][j] - 1);
            }
        }
    }

    // 넓이 출력
    cout << (100 * number) - area;

    return 0; // 정상종료
}