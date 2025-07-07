#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	vector<int> A;
	vector<int> B;

	for (int i = 1; i <= T; i++) {
		int N, M;
		int max_sum = 0;
		int sum = 0;
		cin >> N >> M;

		A.assign(N, 0);
		B.assign(M, 0);

		// A, B 입력
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		// 3가지 case
		if (N > M) {
			// A > B (길이)
			for (int k = 0; k < N - M + 1; k++) {
				sum = 0;
				for (int j = 0; j < M; j++) {
					sum += A[j + k] * B[j];
				}
				max_sum = max(max_sum, sum);
			}
		}
		else if (N == M) {
			// A = B (길이)
			sum = 0;
			for (int j = 0; j < A.size(); j++) {
				sum += A[j] * B[j];
			}
			max_sum = max(max_sum, sum);
		}
		else {
			// A < B (길이)
			for (int k = 0; k < M - N + 1; k++) {
				sum = 0;
				for (int j = 0; j < N; j++) {
					sum += A[j] * B[j + k];
				}
				max_sum = max(max_sum, sum);
			}
		}
		// 출력
		cout << "#" << i << " " << max_sum << "\n";
	}


	return 0;
}