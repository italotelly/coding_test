#include <iostream>

using namespace std;

int N;
bool dp[1005];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dp[2] = true;

	for (int i = 4; i <= 1000; i++)
	{
		dp[i] = !dp[i - 3];
	}

	if (dp[N] == false) {
		cout << "SK\n";
	}
	else if (dp[N] == true) {
		cout << "CY\n";
	}

	return 0;
}