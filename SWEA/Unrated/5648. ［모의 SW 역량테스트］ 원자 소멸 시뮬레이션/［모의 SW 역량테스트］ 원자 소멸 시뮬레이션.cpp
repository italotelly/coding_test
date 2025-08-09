#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T;
int N;
// 스케일 2배 적용: 0..4000 범위를 쓰므로 배열 크기 확장
int map[4101][4101];

int rst;
int energy_sum;

struct atom
{
	int x;
	int y;
	int d;
	int K;
};

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

atom atoms[1100];

void init() {
	memset(atoms, 0, sizeof(atoms));
	memset(map, 0, sizeof(map));
	energy_sum = 0;
}

bool inRange(int y, int x) {
	if (y < 0 || y > 4000 || x < 0 || x > 4000) {
		return false;
	}
	return true;
}

void solve() {
	int j = 4001;

	// 이번 틱에 건드린 좌표만 모아두기
	pair<int,int> touched[1200];
	int tcnt;

	while (j--) {
		// 틱마다 카운트/표시를 새로 계산  (전역 memset 제거)
		tcnt = 0;

		for (int i = 0; i < N; i++)
		{
			// 원자 소멸 시 continue
			if (atoms[i].K == 0) {
				continue;
			}
			// 원자가 범위 밖을 나갈 시 continue;
			int ny = atoms[i].y + dy[atoms[i].d];
			int nx = atoms[i].x + dx[atoms[i].d];
			if (!inRange(ny, nx)) {
				atoms[i].K = 0; // 범위 이탈 시 소멸
				continue;
			}

			// 이동
			atoms[i].y = ny;
			atoms[i].x = nx;

			// 해당 칸 원자 수
			if (map[ny][nx] == 0) touched[tcnt++] = {ny, nx};
			map[ny][nx] += 1;
		}

		// check time
		bool anyAlive = false;
		for (int i = 0; i < N; i++)
		{
			if (atoms[i].K == 0) continue;
			anyAlive = true;

			// 충돌 시 에너지 총합 계산 + map에서도 뺴기
			int y = atoms[i].y;
			int x = atoms[i].x;
			if (map[y][x] > 1) {
				energy_sum += atoms[i].K;
				atoms[i].K = 0;
			}
		}

		// 이번 틱에 썼던 좌표만 map을 0으로 되돌림
		for (int k = 0; k < tcnt; ++k) {
			int y = touched[k].first;
			int x = touched[k].second;
			map[y][x] = 0;
		}

		// 더 이상 살아있는 원자가 없으면 조기 종료
		if (!anyAlive) break;
	}

	rst = energy_sum;
}

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		init();

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> atoms[i].x >> atoms[i].y >> atoms[i].d >> atoms[i].K;
			// 스케일 2배(교차 충돌 보정) + 1000 오프셋
			atoms[i].x = (atoms[i].x + 1000) * 2;
			atoms[i].y = (atoms[i].y + 1000) * 2;
			// 시작 셀 카운트는 틱 내에서 계산하므로 여기선 건드리지 않음
		}

		solve();

		// 출력
		cout << "#" << tc + 1 << " " << rst << "\n";
	}

	return 0;
}
