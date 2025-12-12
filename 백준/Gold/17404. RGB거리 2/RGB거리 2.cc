#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1005][3];
int dp[1005][3];
int rst = 21e8;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 0; i < 3; i++)
	{
		// 첫 번째 RGB 색상 정하기
		for (int j = 0; j < 3; j++)
		{
			if (i == j) dp[1][j] = arr[1][j];
			else dp[1][j] = 21e8;
		}

		// dp 점화식
		for (int j = 2; j <= N; j++)
		{
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		// N번 집 겹치지 않게 결과 저장
		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			rst = min(rst, dp[N][j]);
		}
	}

	cout << rst << "\n";

	return 0;
}