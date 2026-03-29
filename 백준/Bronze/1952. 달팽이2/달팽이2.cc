#include <iostream>

using namespace std;

int m, n;

// 오, 하, 왼, 위
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= m || x >= n) {
		return false;
	}
	return true;
}

bool visited[105][105];
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	int ny = 0;
	int nx = 0;
	int dir = 0;

	visited[ny][nx] = true;

	for (int i = 0; i < m * n - 1; i++)
	{
		ny += dy[dir];
		nx += dx[dir];

		if (!inRange(ny, nx) || visited[ny][nx]) {			
			ny -= dy[dir];
			nx -= dx[dir];
			dir++;
			dir %= 4;
			ny += dy[dir];
			nx += dx[dir];
			rst++;
		}
		visited[ny][nx] = true;
	}

	cout << rst << "\n";

	return 0;
}