#include <iostream>
#include <algorithm>

using namespace std;

int N;
int r[505];
int c[505];
long long dp[505][505];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> r[i + 1] >> c[i + 1];
	}

	for (int len = 1; len < N; len++)
	{
		for (int i = 1; i + len <= N; i++)
		{
			int j = i + len;
			dp[i][j] = 1e18;
			for (int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j]);
			}
		}
	}

	cout << dp[1][N] << "\n";

	return 0;
}