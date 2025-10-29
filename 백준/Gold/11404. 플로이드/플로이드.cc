#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int MAP[105][105];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) {
				MAP[i][j] = 0;
			}
			else {
				MAP[i][j] = 21e8;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		MAP[from][to] = min(MAP[from][to], cost);
	}

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (MAP[i][j] == 21e8 || MAP[j][k] == 21e8)
					continue;
				MAP[i][k] = min(MAP[i][k], MAP[i][j] + MAP[j][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (MAP[i][j] == 21e8) {
				cout << "0 ";
			}
			else {
				cout << MAP[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}