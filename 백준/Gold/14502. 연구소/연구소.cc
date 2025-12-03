#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos
{
	int y, x;
};

int N, M;
int MAP[10][10];
int temp_MAP[10][10];

vector<pos> virus;
vector<pos> space;

int path[3];

int rst;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

void bfs() {
	queue<pos> q;
	for (int i = 0; i < virus.size(); i++)
	{
		q.push({ virus[i].y, virus[i].x });
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (!inRange(ny, nx)) continue;
			if (temp_MAP[ny][nx] != 0) continue;

			temp_MAP[ny][nx] = 2;
			q.push({ ny, nx });
		}
	}
}

void chk() {
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp_MAP[i][j] == 0) {
				sum++;
			}
		}
	}
	rst = max(rst, sum);
}

void dfs(int lev, int st_idx) {
	if (lev == 3) {
		MAP[space[path[0]].y][space[path[0]].x] = 1;
		MAP[space[path[1]].y][space[path[1]].x] = 1;
		MAP[space[path[2]].y][space[path[2]].x] = 1;
		memcpy(temp_MAP, MAP, sizeof(MAP));
		bfs();
		chk();
		MAP[space[path[0]].y][space[path[0]].x] = 0;
		MAP[space[path[1]].y][space[path[1]].x] = 0;
		MAP[space[path[2]].y][space[path[2]].x] = 0;
		return;
	}

	for (int i = st_idx; i < space.size(); i++)
	{
		path[lev] = i;
		dfs(lev + 1, i + 1);
		path[lev] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				virus.push_back({ i ,j });
			}
			else if (MAP[i][j] == 0) {
				space.push_back({ i ,j });
			}
		}
	}

	dfs(0, 0);

	cout << rst << "\n";

	return 0;
}