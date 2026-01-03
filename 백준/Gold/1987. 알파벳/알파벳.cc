#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char MAP[25][25];
bool visited[25][25];
bool alphabet[30];

int rst;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	if (y<1 || x<1 || y>R || x>C) {
		return false;
	}
	return true;
}

void dfs(int y, int x, int count) {
	visited[y][x] = 1;
	alphabet[MAP[y][x] - 'A'] = 1;
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (!inRange(ny, nx) || visited[ny][nx] || alphabet[MAP[ny][nx] - 'A']) continue;
		flag = 1;
		dfs(ny, nx, count + 1);
	}
	visited[y][x] = 0;
	alphabet[MAP[y][x] - 'A'] = 0;
	if (!flag) {
		rst = max(rst, count);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			MAP[i][j + 1] = s[j];
		}
	}

	dfs(1, 1, 1);

	cout << rst << "\n";

	return 0;
}