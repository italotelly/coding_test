#include <iostream>

using namespace std;

using ll = long long;

ll MOD = 1000000000;

int N;
ll dp[101][10][1 << 10];
ll rst;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	if (N < 10) {
		cout << "0\n";
		return 0;
	}
	else {
		for (int i = 1; i < 10; i++)
		{
			dp[1][i][1 << i] = 1;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int mask = 0; mask < (1 << 10); mask++)
				{
					int new_mask = mask | (1 << j);
					if (j - 1 >= 0) {
						dp[i][j][new_mask] = (dp[i][j][new_mask] + dp[i - 1][j - 1][mask]) % MOD;
					}
					if (j + 1 < 10) {
						dp[i][j][new_mask] = (dp[i][j][new_mask] + dp[i - 1][j + 1][mask]) % MOD;
					}
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			rst += (dp[N][i][(1 << 10) - 1] % MOD);
		}

		cout << rst % MOD << "\n";
	}

	return 0;
}