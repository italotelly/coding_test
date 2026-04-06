#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int W[16][16];
int dp[16][1 << 16];

int dfs(int cur, int mask) {
	if (mask == (1 << N) - 1) {
		if (W[cur][0] == 0) return 21e8;
		return W[cur][0];
	}

	if (dp[cur][mask] != -1) return dp[cur][mask];

	int ret = 21e8;
	for (int next = 0; next < N; next++)
	{
		// 이미 방문 했으면 pass
		if (mask & (1 << next)) continue;
		// 길이 없으면 pass
		if (W[cur][next] == 0) continue;
		ret = min(ret, W[cur][next] + dfs(next, mask | (1 << next)));
	}
	dp[cur][mask] = ret;

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1) << "\n";

	return 0;
}