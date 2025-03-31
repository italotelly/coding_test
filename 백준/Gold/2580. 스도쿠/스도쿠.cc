#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> empty_cells; // 0인 좌표 저장

// 현재 위치(x, y)에 num을 넣을 수 있는지 검사
bool isValid(int x, int y, int num)
{
    // 행과 열 검사
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == num || board[i][y] == num)
            return false;
    }

    // 3x3 박스 검사
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startX + i][startY + j] == num)
                return false;
        }
    }

    return true;
}

// DFS를 활용한 백트래킹
bool solve(int idx)
{
    if (idx == empty_cells.size())
        return true; // 모든 빈칸을 채우면 종료

    int x = empty_cells[idx].first;
    int y = empty_cells[idx].second;

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(x, y, num))
        { // 숫자 배치 가능하면
            board[x][y] = num;

            if (solve(idx + 1))
                return true; // 다음 빈칸 탐색

            board[x][y] = 0; // 백트래킹 (원상 복구)
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 스도쿠 입력 받기
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                empty_cells.push_back({i, j});
        }
    }

    solve(0); // DFS 시작

    // 정답 출력
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
