#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int W[105];
int V[105];

int dp[105][100005];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - W[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}