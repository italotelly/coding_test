#include <iostream>
#include <algorithm>

using namespace std;

int T;
int K;
long long sum[505];
long long dp[505][505];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> K;
		sum[0] = 0;
		for (int a = 0; a < K; a++)
		{
			int b;
			cin >> b;
			sum[a + 1] = sum[a] + b;
		}

		for (int len = 1; len < K; len++)
		{
			for (int i = 1; i + len <= K; i++)
			{
				int j = i + len;
				dp[i][j] = 1e18;
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (sum[j] - sum[i - 1]));
				}
			}
		}
		cout << dp[1][K] << "\n";
	}

	return 0;
}