#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct shark
{
	int y, x;
	int lev;
	int exp;
};

struct fish
{
	int y, x;
	int cost;
};

struct eat
{
	int y, x;
	int dist;
};

int N;
int MAP[25][25];
int visited[25][25];
int rst;

shark baby;
vector<fish> fishes;
vector<eat> can_eat;

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool compare(eat a, eat b) {
	if (a.dist == b.dist) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
	return a.dist < b.dist;
}

void bfs() {
	queue<eat> q;
	q.push({ baby.y, baby.x, 0});
	visited[baby.y][baby.x] = 1;

	while (!q.empty()) {
		eat now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (!inRange(ny, nx)) continue;
			if (visited[ny][nx]) continue;

			if (MAP[ny][nx] <= baby.lev) {
				if (MAP[ny][nx] < baby.lev && MAP[ny][nx] > 0) {
					can_eat.push_back({ny, nx, now.dist + 1});
					visited[ny][nx] = 1;
					q.push({ ny, nx, now.dist + 1 });
				}
				else {
					visited[ny][nx] = 1;
					q.push({ ny, nx, now.dist + 1 });
				}
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) continue;
			// 아기 상어
			if (MAP[i][j] == 9) {
				MAP[i][j] = 0;
				baby.y = i;
				baby.x = j;
				baby.lev = 2;
				baby.exp = 0;
			}
			// 물고기
			else {
				fishes.push_back({i, j, MAP[i][j]});
			}
		}
	}

	if (fishes.size() == 0) {
		cout << rst << " ";
		return 0;
	}

	for (int i = 0; i < fishes.size(); i++)
	{
		can_eat.clear();
		memset(visited, 0, sizeof(visited));
		bfs();
		if (can_eat.size() == 0) break;
		sort(can_eat.begin(), can_eat.end(), compare);
		baby.y = can_eat[0].y;
		baby.x = can_eat[0].x;
		baby.exp += 1;
		if (baby.exp == baby.lev) {
			baby.exp = 0;
			baby.lev += 1;
		}
		rst += can_eat[0].dist;
		MAP[baby.y][baby.x] = 0;
	}

	cout << rst << "\n";

	return 0;
}