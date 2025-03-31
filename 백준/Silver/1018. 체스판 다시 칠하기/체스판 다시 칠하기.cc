#include <iostream>

using namespace std;

// 체스판 다시 칠하기

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;

    cin >> M >> N;

    char ary[M][N];
    char ary_test[M][N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> ary[i][j];
            ary_test[i][j] = ary[i][j];
        }
    }

    // 정사각형 칠하기
    // 최소 개수 구하기
    int count = 70;
    int sum = 0;

    // 8x8 잡기
    // 처음 start W case or B case
    for (int l = 0; l < M - 7; l++)
    {
        for (int k = 0; k < N - 7; k++)
        {
            for (int t = 0; t < 2; t++)
            {
                sum = 0;
                if (t == 1)
                {
                    if (ary[l][k] == 'W')
                    {
                        ary_test[l][k] = 'B';
                        sum++;
                    }
                    else
                    {
                        ary_test[l][k] = 'W';
                        sum++;
                    }
                }
                for (int i = 0 + l; i < 8 + l; i++)
                {
                    for (int j = 0 + k; j < 8 + k; j++)
                    {
                        if (j == 8 + k - 1)
                        {
                            if ((i < 7 + l) && (ary_test[i][j] != ary[i + 1][j - 7]))
                            {
                                sum++;
                                ary_test[i + 1][j - 7] = ary_test[i][j];
                            }
                            ary_test[i][j] = ary[i][j];
                            break;
                        }
                        if (ary_test[i][j] == 'W')
                        {
                            if (ary_test[i][j + 1] == 'B')
                            {
                                ary_test[i][j] = ary[i][j];
                                continue;
                            }
                            else
                            {
                                ary_test[i][j + 1] = 'B';
                                ary_test[i][j] = ary[i][j];
                                sum++;
                            }
                        }
                        else
                        {
                            if (ary_test[i][j + 1] == 'W')
                            {
                                ary_test[i][j] = ary[i][j];
                                continue;
                            }
                            else
                            {
                                ary_test[i][j + 1] = 'W';
                                ary_test[i][j] = ary[i][j];
                                sum++;
                            }
                        }
                    }
                }
                if (t == 1)
                {
                    ary_test[l][k] = ary[l][k];
                }
                if (count > sum)
                {
                    count = sum;
                }
            }
        }
    }

    cout << count;
    return 0; // 정상종료
}