#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T;
int rst;

int N, M, C;
int map[15][15];
int square[15][15];
int cost[15][15];

void dfs(int sy, int sx, int now, int sum, int max_val) {
	if (sum > C)
		return;
	
	// 종료 조건
	if (now == sx + M) {
		if (cost[sy][sx] < max_val) {
			cost[sy][sx] = max_val;
		}
		return;
	}

	// 선택 안한 경우
	dfs(sy, sx, now + 1, sum, max_val);

	// 선택한 경우
	dfs(sy, sx, now + 1, sum + map[sy][now], max_val + square[sy][now]);
}

void init() {
	memset(map, 0, sizeof(map));
	memset(square, 0, sizeof(square));
	memset(cost, 0, sizeof(cost));
	rst = 0;
}

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		init();
		
		cin >> N >> M >> C;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> map[y][x];
				square[y][x] = map[y][x] * map[y][x];
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x <= N - M; x++)
			{
				// cost 배열 채우기
				dfs(y, x, x, 0, 0);
			}
		}

		// 두 일꾼이 선택하기

		// 1. 같은 라인일 경우
		for (int y1 = 0; y1 < N; y1++)
		{
			for (int x1 = 0; x1 <= N-M; x1++)
			{
				for (int x2 = x1 + M; x2 <= N-M; x2++)
				{
					int total = cost[y1][x1] + cost[y1][x2];
					if (total > rst) rst = total;
				}
			}
		}

		// 다른 라인일 경우
		for (int y1 = 0; y1 < N; y1++)
		{
			for (int y2 = y1 + 1; y2 < N; y2++)
			{
				for (int x1 = 0; x1 <= N - M; x1++)
				{
					for (int x2 = 0; x2 <= N - M; x2++)
					{
						int total = cost[y1][x1] + cost[y2][x2];
						if (total > rst) rst = total;
					}
				}
			}
		}

		// 출력
		cout << "#" << tc + 1 << " " << rst << "\n";
	}

	return 0;
}