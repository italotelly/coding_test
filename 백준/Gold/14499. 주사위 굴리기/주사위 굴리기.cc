#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
int MAP[25][25];

int dice_y, dice_x;
int dice[6];
int temp_dice[6];

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

int dir_move[4][6] = {
	{4, 2, 1, 6, 5, 3},
	{3, 2, 6, 1, 5, 4},
	{2, 6, 3, 4, 1, 5},
	{5, 1, 3, 4, 6, 2}
};

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> dice_y >> dice_x;
	cin >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int dir;
		cin >> dir;

		int ny = dice_y + dy[dir - 1];
		int nx = dice_x + dx[dir - 1];

		if (!inRange(ny, nx)) continue;
		dice_y = ny;
		dice_x = nx;
		if (MAP[ny][nx] == 0) {
			memcpy(temp_dice, dice, sizeof(dice));
			for (int i = 0; i < 6; i++)
			{
				dice[i] = temp_dice[dir_move[dir - 1][i] - 1];
			}
			MAP[ny][nx] = dice[5];
			cout << dice[0] << "\n";
		}
		else if (MAP[ny][nx] != 0) {
			memcpy(temp_dice, dice, sizeof(dice));
			for (int i = 0; i < 6; i++)
			{
				dice[i] = temp_dice[dir_move[dir - 1][i] - 1];
			}
			dice[5] = MAP[ny][nx];
			MAP[ny][nx] = 0;
			cout << dice[0] << "\n";
		}
	}

	return 0;
}