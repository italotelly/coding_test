#include <iostream>

using namespace std;

struct state
{
	int y, x;
	int dir;
	// 0 1 2 / 가로 세로 대각선
};

int N;
int MAP[20][20];

int rst;

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > N) {
		return false;
	}
	return true;
}

void dfs(state s) {
	if (s.y == N && s.x == N) {
		rst++;
		return;
	}
	if (s.dir == 0) {
		if (inRange(s.y, s.x + 1) && !MAP[s.y][s.x + 1])
			dfs({ s.y, s.x + 1, 0 });
		if (inRange(s.y + 1, s.x + 1) && !MAP[s.y + 1][s.x + 1] && !MAP[s.y + 1][s.x] && !MAP[s.y][s.x + 1])
			dfs({ s.y + 1, s.x + 1, 2 });
	}
	else if (s.dir == 1) {
		if (inRange(s.y + 1, s.x) && !MAP[s.y + 1][s.x])
			dfs({ s.y + 1, s.x, 1 });
		if (inRange(s.y + 1, s.x + 1) && !MAP[s.y + 1][s.x + 1] && !MAP[s.y + 1][s.x] && !MAP[s.y][s.x + 1])
			dfs({ s.y + 1, s.x + 1, 2 });
	}
	else if (s.dir == 2) {
		if (inRange(s.y, s.x + 1) && !MAP[s.y][s.x + 1])
			dfs({ s.y, s.x + 1, 0 });
		if (inRange(s.y + 1, s.x) && !MAP[s.y + 1][s.x])
			dfs({ s.y + 1, s.x, 1 });
		if (inRange(s.y + 1, s.x + 1) && !MAP[s.y + 1][s.x + 1] && !MAP[s.y + 1][s.x] && !MAP[s.y][s.x + 1])
			dfs({ s.y + 1, s.x + 1, 2 });
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	state st = { 1, 2, 0 };
	dfs(st);

	cout << rst << "\n";

	return 0;
}