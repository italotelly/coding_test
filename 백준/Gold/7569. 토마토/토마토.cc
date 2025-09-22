#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int MAP[105][105][105];

int target_cnt;
int rst;

int dy[] = { 0, 0, 0, 0, -1, 1 };
int dx[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 1, -1, 0, 0, 0, 0 };

struct pos
{
	int z, y, x;
};

queue<pos> q;

bool inRange(int z, int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M || z < 0 || z >= H) {
		return false;
	}
	return true;
}

void bfs() {
	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int sz = now.z + dz[i];
			int sy = now.y + dy[i];
			int sx = now.x + dx[i];

			if (!inRange(sz, sy, sx))
				continue;
			if (MAP[sz][sy][sx] != 0)
				continue;
			target_cnt--;
			if (target_cnt == 0) {
				rst = MAP[now.z][now.y][now.x] + 1;
				return;
			}
			MAP[sz][sy][sx] = MAP[now.z][now.y][now.x] + 1;
			q.push({ sz, sy, sx });
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 0) {
					target_cnt++;
				}
				if (MAP[i][j][k] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}

	// 예외처리 1 - 모두 1혹은 -1일시
	if (target_cnt == 0) {
		cout << 0 << "\n";
		return 0;
	}
	// 예외처리 2 - 0인 것 중에 상하좌우앞뒤가 범위 밖 혹은 -1일 때
	int flag = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (MAP[i][j][k] == 0) {
					flag = 0;
					for (int l = 0; l < 6; l++)
					{
						int nz = i + dz[l];
						int ny = j + dy[l];
						int nx = k + dx[l];

						if (!inRange(nz, ny, nx))
							continue;
						if (MAP[nz][ny][nx] == -1)
							continue;
						flag = 1;
						break;
					}
					if (!flag) {
						cout << -1 << "\n";
						return 0;
					}
				}
			}
		}
	}

	// bfs flood fill
	bfs();
	cout << rst - 1 << "\n";

	return 0;
}