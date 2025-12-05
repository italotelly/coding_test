#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R, C;
int T;

int rst;
vector<int> pure;

int MAP[55][55];
int temp_MAP[55][55];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > R || x > C) {
		return false;
	}
	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	cin >> T;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				pure.push_back(i);
			}
		}
	}

	while (T--) {
		// 1. 미세먼지 확산
		memcpy(temp_MAP, MAP, sizeof(MAP));
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (MAP[i][j] > 4) {
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (!inRange(ny, nx) || MAP[ny][nx] == -1) continue;
						
						temp_MAP[ny][nx] += MAP[i][j] / 5;
						cnt++;
					}
					temp_MAP[i][j] -= (MAP[i][j] / 5) * cnt;
				}
			}
		}
		memcpy(MAP, temp_MAP, sizeof(MAP));

		// 2. 공기 청정기 작동
		// 위
		// 상
		for (int i = 1; i < C; i++)
		{
			MAP[1][i] = temp_MAP[1][i + 1];
		}
		// 하
		for (int i = 3; i <= C; i++)
		{
			MAP[pure[0]][i] = temp_MAP[pure[0]][i - 1];
		}
		MAP[pure[0]][2] = 0;
		// 좌
		for (int i = 2; i < pure[0]; i++)
		{
			MAP[i][1] = temp_MAP[i - 1][1];
		}
		// 우
		for (int i = 1; i < pure[0]; i++)
		{
			MAP[i][C] = temp_MAP[i + 1][C];
		}
		// 아래
		// 상
		for (int i = 3; i <= C; i++)
		{
			MAP[pure[1]][i] = temp_MAP[pure[1]][i - 1];
		}
		MAP[pure[1]][2] = 0;
		// 하
		for (int i = 1; i < C; i++)
		{
			MAP[R][i] = temp_MAP[R][i + 1];
		}
		// 좌
		for (int i = pure[1] + 1; i < R; i++)
		{
			MAP[i][1] = temp_MAP[i + 1][1];
		}
		// 우
		for (int i = pure[1] + 1; i <= R; i++)
		{
			MAP[i][C] = temp_MAP[i - 1][C];
		}

	}

	// 결과
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (MAP[i][j] > 0) {
				rst += MAP[i][j];
			}
		}
	}
	cout << rst << "\n";

	return 0;
}