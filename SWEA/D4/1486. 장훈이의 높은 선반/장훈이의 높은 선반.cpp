#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// N 사람 수
// B 최소 높이
int N, B;
vector<int> v;
int sol;

int dfs(int x, int target) {
	if (target >= B) {
		sol = min(sol, target - B);
		return sol;
	}

	if (x == N) return sol;

	// 점원을 선택한 경우
	dfs(x + 1, target + v[x]);

	// 점원을 선택하지 않은 경우
	dfs(x + 1, target);
}


// 최소 값 구하기, BFS
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N >> B;
		sol = INT_MAX;

		v.assign(N, 0);
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}

		sol = dfs(0, 0);

		// 출력
		cout << "#" << i << " " << sol << "\n";
	}

	return 0;
}