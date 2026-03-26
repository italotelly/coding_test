#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> up(N + 2, 0);
	vector<int> down(N + 2, 0);

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		if (k > 0) {
			up[k]++;
		}
		else {
			down[-k]++;
		}
	}

	// 진실을 말하는 사람의 수를 누적할 배열
	vector<int> pref(N + 2, 0);
	vector<int> suff(N + 2, 0);

	// 1. k > 0 인 경우의 누적합 (k <= x 인 사람의 수)
	int current_up_sum = 0;
	for (int i = 0; i <= N; i++) {
		current_up_sum += up[i];
		pref[i] = current_up_sum;
	}

	// 2. k <= 0 인 경우의 누적합 (k >= x 인 사람의 수)
	int current_down_sum = 0;
	for (int i = N; i >= 0; i--) {
		current_down_sum += down[i];
		suff[i] = current_down_sum;
	}

	// 정답을 담을 배열
	vector<int> rst;

	// 0명부터 N명까지 모든 경우의 수를 탐색
	for (int x = 0; x <= N; x++) {
		if (pref[x] + suff[x] == N - x) {
			rst.push_back(x);
		}
	}

	cout << rst.size() << "\n";

	for (int ans : rst) {
		cout << ans << " ";
	}
	cout << "\n";

	return 0;
}