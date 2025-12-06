#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int rst;

int row_num = 3;
int col_num = 3;

int A[205][205];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> r >> c >> k;
	
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> A[i][j];
		}
	}

	while (rst <= 100) {
		// 종료 조건
		if (A[r][c] == k) break;

		// R 연산
		if (row_num >= col_num) {
			for (int i = 1; i <= row_num; i++)
			{
				map<int, int> m;
				for (int j = 1; j <= 100; j++)
				{
					if (A[i][j]) {
						m[A[i][j]]++;
					}
				}
				vector<pair<int, int>> v;
				for (auto it = m.begin(); it != m.end(); it++) {
					v.push_back({ it->first, it->second });
				}
				sort(v.begin(), v.end(), compare);
				for (int j = 1; j < v.size() * 2; j+=2)
				{
					A[i][j] = v[j / 2].first;
					A[i][j + 1] = v[j / 2].second;
				}
				for (int j = v.size() * 2 + 1; j <= 100; j ++)
				{
					A[i][j] = 0;
				}
				col_num = max(col_num, (int)(v.size() * 2));
			}
		}
		// C 연산
		else {
			for (int i = 1; i <= col_num; i++)
			{
				map<int, int> m;
				for (int j = 1; j <= 100; j++)
				{
					if (A[j][i]) {
						m[A[j][i]]++;
					}
				}
				vector<pair<int, int>> v;
				for (auto it = m.begin(); it != m.end(); it++) {
					v.push_back({ it->first, it->second });
				}
				sort(v.begin(), v.end(), compare);
				for (int j = 1; j < v.size() * 2; j += 2)
				{
					A[j][i] = v[j / 2].first;
					A[j + 1][i] = v[j / 2].second;
				}
				for (int j = v.size() * 2 + 1; j <= 100; j++)
				{
					A[j][i] = 0;
				}
				row_num = max(row_num, (int)(v.size() * 2));
			}
		}
		rst++;
	}

	if (rst > 100) {
		cout << "-1\n";
	}
	else {
		cout << rst << "\n";
	}

	return 0;
}