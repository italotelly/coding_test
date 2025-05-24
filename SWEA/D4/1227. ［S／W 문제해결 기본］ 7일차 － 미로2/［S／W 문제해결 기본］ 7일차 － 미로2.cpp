#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int ary[100][100];
int visited[100][100];
int solution;

void dfs(int x, int y) {
	if (ary[x][y] == 3) {
		solution = 1;
		return;
	}

	visited[x][y] = 1;

	// 상
	if (x - 1 >= 0 && !visited[x - 1][y] && ary[x - 1][y] != 1)
		dfs(x - 1, y);
	// 하
	if (x + 1 < 100 && !visited[x + 1][y] && ary[x + 1][y] != 1)
		dfs(x + 1, y);
	// 좌
	if (y - 1 >= 0 && !visited[x][y - 1] && ary[x][y - 1] != 1)
		dfs(x, y - 1);
	// 우
	if (y + 1 < 100 && !visited[x][y + 1] && ary[x][y + 1] != 1)
		dfs(x, y + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	string line;

	for (int i = 1; i <= 10; i++) {
		cin >> TC;
		solution = 0;
		memset(visited, 0, sizeof(visited));

		// 미로 입력
		for (int j = 0; j < 100; j++) {
			cin >> line;
			for (int k = 0; k < 100; k++) {
				ary[j][k] = line[k] - '0';
			}
		}

		dfs(1, 1);
		cout << "#" << TC << " " << solution << "\n";
	}

	return 0;
}
