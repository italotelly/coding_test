#include <iostream>
#include <string>

using namespace std;

int N;
string s;
int dp[3][3][3][3];
int t_cnt, g_cnt, f_cnt, p_cnt;
int rst;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> s;

	// T G F P
	dp[0][0][0][0] = 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'T') {
			t_cnt++; t_cnt %= 3;
		}
		else if (s[i] == 'G') {
			g_cnt++; g_cnt %= 3;
		}
		else if (s[i] == 'F') {
			f_cnt++; f_cnt %= 3;
		}
		else if (s[i] == 'P') {
			p_cnt++; p_cnt %= 3;
		}
		if (dp[t_cnt][g_cnt][f_cnt][p_cnt]) {
			rst += dp[t_cnt][g_cnt][f_cnt][p_cnt];
		}
		dp[t_cnt][g_cnt][f_cnt][p_cnt]++;
	}

	cout << rst << "\n";

	return 0;
}