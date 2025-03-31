#include <iostream>
#include <vector>

using namespace std;

void star(vector<vector<char>> &v, int startX, int startY, int length)
{
    if (length == 1)
        return;

    int newLength = length / 3;

    // 가운데 부분을 공백으로 설정
    for (int i = startX + newLength; i < startX + 2 * newLength; i++)
    {
        for (int j = startY + newLength; j < startY + 2 * newLength; j++)
        {
            v[i][j] = ' ';
        }
    }

    // 9개 부분에 대해 재귀적으로 호출
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) // 가운데 부분은 이미 비웠으므로 건너뜀
                continue;
            star(v, startX + i * newLength, startY + j * newLength, newLength);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<vector<char>> V(N, vector<char>(N, '*'));

    star(V, 0, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << V[i][j];
        }
        cout << "\n";
    }

    return 0;
}