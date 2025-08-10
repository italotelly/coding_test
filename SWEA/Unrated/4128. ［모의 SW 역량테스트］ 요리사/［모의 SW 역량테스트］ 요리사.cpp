#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

int rst;
int min_val = 999999;

int N;
int map[20][20];
int half_sum_a;
int half_sum_b;
string comb[13000];
int path[10];
int cnt;

void init() {
	memset(map, 0, sizeof(map));
	memset(path, 0, sizeof(path));
	cnt = 0;
	min_val = 999999;
}

void step1(int lev, int start_idx) {
	if (lev == N / 2) {
		comb[cnt].clear();
		for (int i = 0; i < N / 2; i++)
		{
			comb[cnt] += (char)(path[i] + '0');
		}
		cnt++;
		return;
	}
	for (int i = start_idx; i < N; i++)
	{
		path[lev] = i;
		step1(lev + 1, i + 1);
		path[lev] = 0;
	}
}

void solve() {
	// step1. N C N/2
	step1(0, 0);

	// step2. sum 구하기
	
	for (int i = 0; i < cnt / 2; i++)
	{
		half_sum_a = 0;
		half_sum_b = 0;

		for (int j = 0; j < comb[i].size(); j++)
		{
			for (int k = 0; k < comb[i].size(); k++)
			{
				half_sum_a += map[(comb[i][j]) - '0'][(comb[i][k]) - '0'];
			}
		}

		for (int j = 0; j < comb[cnt - i - 1].size(); j++)
		{
			for (int k = 0; k < comb[cnt - i - 1].size(); k++)
			{
				half_sum_b += map[(comb[cnt - i - 1][j]) - '0'][(comb[cnt - i - 1][k]) - '0'];
			}
		}

		min_val = min(min_val, abs(half_sum_a - half_sum_b));
	}

	rst = min_val;
}

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		init();

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		solve();

		// 출력
		cout << "#" << tc + 1 << " " << rst << "\n";
	}

	return 0;
}