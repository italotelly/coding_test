#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

struct pos
{
	int val;
	int a, b, c, d;
};

struct group
{
	int sum;
	int cnt;
};

int N, L, R;
pos MAP[55][55];
int temp_MAP[55][55];
vector<pair<int, int>> group_num;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int rst;
int cnt;

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

void bfs(int y, int x, int num) {
	queue<pair<int, int >> q;
	temp_MAP[y][x] = num;
	q.push({ y, x });
	group_num.push_back({ MAP[y][x].val, 1 });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (MAP[now.first][now.second].a == 1) {
			int ny = now.first + dy[0];
			int nx = now.second + dx[0];

			if (inRange(ny, nx) && temp_MAP[ny][nx] == 0) {
				q.push({ ny, nx });
				temp_MAP[ny][nx] = num;
				group_num[num - 1].first += MAP[ny][nx].val;
				group_num[num - 1].second++;
			}
		}
		if (MAP[now.first][now.second].b == 1) {
			int ny = now.first + dy[1];
			int nx = now.second + dx[1];

			if (inRange(ny, nx) && temp_MAP[ny][nx] == 0) {
				q.push({ ny, nx });
				temp_MAP[ny][nx] = num;
				group_num[num - 1].first += MAP[ny][nx].val;
				group_num[num - 1].second++;
			}
		}
		if (MAP[now.first][now.second].c == 1) {
			int ny = now.first + dy[2];
			int nx = now.second + dx[2];

			if (inRange(ny, nx) && temp_MAP[ny][nx] == 0) {
				q.push({ ny, nx });
				temp_MAP[ny][nx] = num;
				group_num[num - 1].first += MAP[ny][nx].val;
				group_num[num - 1].second++;
			}
		}
		if (MAP[now.first][now.second].d == 1) {
			int ny = now.first + dy[3];
			int nx = now.second + dx[3];

			if (inRange(ny, nx) && temp_MAP[ny][nx] == 0) {
				q.push({ ny, nx });
				temp_MAP[ny][nx] = num;
				group_num[num - 1].first += MAP[ny][nx].val;
				group_num[num - 1].second++;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j].val;
		}
	}

	while (true) {
		// 1. 국경선 개방 여부 chk
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (!inRange(ny, nx)) continue;
					
					if (abs(MAP[i][j].val - MAP[ny][nx].val) <= R && abs(MAP[i][j].val - MAP[ny][nx].val) >= L) {
						if (k == 0) {
							MAP[i][j].a = 1;
						}
						else if (k == 1) {
							MAP[i][j].b = 1;
						}
						else if (k == 2) {
							MAP[i][j].c = 1;
						}
						else if (k == 3) {
							MAP[i][j].d = 1;
						}
					}
					else {
						if (k == 0) {
							MAP[i][j].a = 0;
						}
						else if (k == 1) {
							MAP[i][j].b = 0;
						}
						else if (k == 2) {
							MAP[i][j].c = 0;
						}
						else if (k == 3) {
							MAP[i][j].d = 0;
						}
					}
				}
			}
		}

		// 2. 인구 이동 시작
		// flood fill, 연합 chk
		cnt = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp_MAP[i][j] == 0) {
					if (MAP[i][j].a == 1 || MAP[i][j].b == 1 || MAP[i][j].c == 1 || MAP[i][j].d == 1) {
						bfs(i, j, cnt);
						cnt++;
					}
				}
			}
		}
		// 더 이상 인구 이동 없음
		if (cnt == 1) {
			break;
		}
		// 인구 이동
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (temp_MAP[i][j] > 0) {
					MAP[i][j].val = group_num[temp_MAP[i][j] - 1].first / group_num[temp_MAP[i][j] - 1].second;
				}
			}
		}

		// 연합 해체 및 필요 변수 초기화
		group_num.clear();
		memset(temp_MAP, 0, sizeof(temp_MAP));
		rst++;
	}

	cout << rst << "\n";

	return 0;
}