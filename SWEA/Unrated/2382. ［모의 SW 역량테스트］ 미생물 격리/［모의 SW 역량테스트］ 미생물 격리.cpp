#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct BUG {
	int y, x;
	int number;
	int d;
};

int T, N, M, K;
BUG bug[1000];
int dy[] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dx[] = { 0, 0, -1, 1 };

void init() {
	memset(bug, 0, sizeof(bug));
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> bug[i].y >> bug[i].x >> bug[i].number >> bug[i].d;
		bug[i].d -= 1; // 0-based
	}
}

void reflection(BUG &b) {
	if (b.d == 0) b.d = 1;
	else if (b.d == 1) b.d = 0;
	else if (b.d == 2) b.d = 3;
	else b.d = 2;
}

void solve() {
	while (M--) {
		static int total[101][101], maxCnt[101][101], maxIdx[101][101], dir[101][101];
		memset(total, 0, sizeof(total));
		memset(maxCnt, 0, sizeof(maxCnt));
		memset(maxIdx, -1, sizeof(maxIdx));
		memset(dir, -1, sizeof(dir));

		// 군집 이동
		for (int i = 0; i < K; i++) {
			if (bug[i].number == 0) continue;

			bug[i].y += dy[bug[i].d];
			bug[i].x += dx[bug[i].d];

			// 경계선 도착
			if (bug[i].y == 0 || bug[i].y == N - 1 || bug[i].x == 0 || bug[i].x == N - 1) {
				bug[i].number /= 2;
				reflection(bug[i]);
			}

			total[bug[i].y][bug[i].x] += bug[i].number;

			if (bug[i].number > maxCnt[bug[i].y][bug[i].x]) {
				maxCnt[bug[i].y][bug[i].x] = bug[i].number;
				maxIdx[bug[i].y][bug[i].x] = i;
				dir[bug[i].y][bug[i].x] = bug[i].d;
			}
		}

		// 같은 위치 군집 합치기
		for (int i = 0; i < K; i++) {
			if (bug[i].number == 0) continue;
			int y = bug[i].y, x = bug[i].x;

			if (maxIdx[y][x] == i) {
				bug[i].number = total[y][x];
				bug[i].d = dir[y][x];
			}
			else {
				bug[i].number = 0;
			}
		}
	}

	// 최종 합산
	int ans = 0;
	for (int i = 0; i < K; i++) ans += bug[i].number;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		cout << "#" << tc << " ";
		solve();
		cout << "\n";
	}
	return 0;
}
