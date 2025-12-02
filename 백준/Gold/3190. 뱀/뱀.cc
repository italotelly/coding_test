#include <iostream>
#include <deque>

using namespace std;

int N, K;
int board[105][105];
int L;

int direction = 3;
int rst;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int change_dir[4][2] = {
	{2, 3},
	{3, 2},
	{1, 0},
	{0, 1}
};

bool inRange(int y, int x) {
	if (y < 1 || x < 1 || y > N || x > N) {
		return false;
	}
	return true;
}

deque<pair<int, int>> snake;
pair<int, int> change_info[105];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	// 사과
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	// 뱀
	snake.push_back({ 1, 1 });
	board[1][1] = 2;

	// 뱀 방향 전환 정보
	cin >> L;

	int flag = 0;
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		if (b == 'L') {
			change_info[i] = { a, 0 };
		}
		else if (b == 'D') {
			change_info[i] = { a, 1 };
		}
	}

	int cnt = 0;
	while (true) {
		while (rst == change_info[cnt].first) {
			direction = change_dir[direction][change_info[cnt].second];
			cnt++;
		}
		// 머리 늘리기
		int ny = snake.front().first + dy[direction];
		int nx = snake.front().second + dx[direction];

		// 자기 자신인 경우 or 벽인 경우 게임 종료
		if (!inRange(ny, nx) || board[ny][nx] == 2) {
			flag = 1;
			break;
		}

		// 사과인 경우
		if (board[ny][nx] == 1) {
			board[ny][nx] = 2;
			snake.push_front({ ny, nx });
		}
		// 사과가 아닌 경우
		else if (board[ny][nx] == 0) {
			board[ny][nx] = 2;
			board[snake.back().first][snake.back().second] = 0;
			snake.push_front({ ny, nx });
			snake.pop_back();
		}
		rst++;
	}

	cout << rst + 1 << "\n";

	return 0;
}