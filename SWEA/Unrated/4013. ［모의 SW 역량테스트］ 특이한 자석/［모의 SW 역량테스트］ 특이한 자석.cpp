#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void rotate(deque<int>& magnet, int dir) {
	if (dir == 1) {  // 시계방향
		int temp = magnet.back();
		magnet.pop_back();
		magnet.push_front(temp);
	}
	else if (dir == -1) {  // 반시계방향
		int temp = magnet.front();
		magnet.pop_front();
		magnet.push_back(temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int K;
		cin >> K;

		vector<deque<int>> magnets(4, deque<int>(8));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnets[i][j];
			}
		}

		while (K--) {
			int idx, dir;
			cin >> idx >> dir;
			idx--;  // 0-indexed

			vector<int> rotateDir(4, 0);
			rotateDir[idx] = dir;

			// 오른쪽 전파
			for (int i = idx; i < 3; i++) {
				if (magnets[i][2] != magnets[i + 1][6]) {
					rotateDir[i + 1] = -rotateDir[i];
				}
				else break;
			}

			// 왼쪽 전파
			for (int i = idx; i > 0; i--) {
				if (magnets[i][6] != magnets[i - 1][2]) {
					rotateDir[i - 1] = -rotateDir[i];
				}
				else break;
			}

			// 회전 적용
			for (int i = 0; i < 4; i++) {
				if (rotateDir[i] != 0) {
					rotate(magnets[i], rotateDir[i]);
				}
			}
		}

		// 점수 계산
		int sum = 0;
		if (magnets[0][0] == 1) sum += 1;
		if (magnets[1][0] == 1) sum += 2;
		if (magnets[2][0] == 1) sum += 4;
		if (magnets[3][0] == 1) sum += 8;

		cout << "#" << t << " " << sum << "\n";
	}

	return 0;
}
