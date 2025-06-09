#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y, vector<vector<int>> &chk, int N) {
	chk[x][y] = 1; // 방문 표시

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && chk[nx][ny] == 0) {
			dfs(nx, ny, chk, N);
		}
	}
}

// 안전 영역
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));
	int max_height = 0;

	// 입력 받기 + 최대 높이 구하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			max_height = max(max_height, v[i][j]);
		}
	}

	int answer = 1; // 비가 안 올 경우를 위해 최소값 1부터 시작

	for (int h = 1; h <= max_height; h++) {
		vector<vector<int>> chk(N, vector<int>(N, 0)); // 0: 안전, 1: 침수 또는 방문
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v[i][j] <= h) chk[i][j] = 1; // 잠긴 곳
			}
		}

		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (chk[i][j] == 0) {
					dfs(i, j, chk, N);
					count++;
				}
			}
		}
		answer = max(answer, count);
	}

	cout << answer << '\n';
	return 0;
}
