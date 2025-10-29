#include <iostream>

using namespace std;

int N, M;
int MAP[1030][1030];
int dp[1030][1030];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	dp[0][0] = MAP[0][0];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i == 0) {
				dp[i][j] = dp[i][j - 1] + MAP[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + MAP[i][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + MAP[i][j];
				for (int k = 0; k < j; k++)
				{
					dp[i][j] += MAP[i][k];
				}
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans;
		x1 -= 1;
		x2 -= 1;
		y1 -= 1;
		y2 -= 1;
		if (x1 == 0 && y1 == 0) {
			ans = dp[x2][y2];
		}
		else if (x1 == 0) {
			ans = dp[x2][y2] - dp[x2][y1 - 1];
		}
		else if (y1 == 0) {
			ans = dp[x2][y2] - dp[x1 - 1][y2];
		}
		else {
			ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		}
		cout << ans << "\n";
	}

	return 0;
}