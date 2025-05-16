#include <iostream>
#include <vector>

using namespace std;

// 숫자 배열 회전
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    int N;

    for (int i = 1; i <= T; i++)
    {
        cin >> N;
        vector<vector<int>> board(N, vector<int>(N, 0));

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> board[j][k];
            }
        }

        cout << "#" << i << "\n";
        for (int j = 0; j < N; j++)
        {
            // 90도
            for (int k = N - 1; k >= 0; k--)
            {
                cout << board[k][j];
            }
            cout << " ";
            // 180도
            for (int k = N - 1; k >= 0; k--)
            {
                cout << board[N - j - 1][k];
            }
            cout << " ";
            // 270도
            for (int k = 0; k < N; k++)
            {
                cout << board[k][N - j - 1];
            }
            cout << " ";

            cout << "\n";
        }
    }
    return 0;
}
