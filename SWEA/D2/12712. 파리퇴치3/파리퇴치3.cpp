#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;

	cin >> T;

	int N, M;
	vector<vector<int>> v;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		v.assign(N, vector<int>(N, 0));

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> v[j][k];
			}
		}

		int sum = 0;
		int plus_sum = 0;
		int x_sum = 0;

		// 범위 M 기준으로 합산 후 최대 값 출력
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				// + 형 계산
				// 범위 제한 + 상하좌우
				plus_sum = v[j][k];
				for (int t = 1; t < M; t++) {
					// 상
					if (j - t >= 0) {
						plus_sum += v[j - t][k];
					}
					// 하
					if (j + t < N) {
						plus_sum += v[j + t][k];
					}
					// 좌
					if (k - t >= 0) {
						plus_sum += v[j][k - t];
					}
					// 우
					if (k + t < N) {
						plus_sum += v[j][k + t];
					}
				}
				// x 형 계산
				x_sum = v[j][k];
				for (int t = 1; t < M; t++) {
					// 좌상
					if (j - t >= 0 && k - t >= 0) {
						x_sum += v[j - t][k - t];
					}
					// 우상
					if (j - t >= 0 && k + t < N) {
						x_sum += v[j - t][k + t];
					}
					// 좌하
					if (k - t >= 0 && j + t < N) {
						x_sum += v[j + t][k - t];
					}
					// 우하
					if (k + t < N && j + t < N) {
						x_sum += v[j + t][k + t];
					}
				}
				x_sum = max(x_sum, plus_sum);
				sum = max(x_sum, sum);
			}
		}
		cout << "#" << i << " " << sum << "\n";
	}
}