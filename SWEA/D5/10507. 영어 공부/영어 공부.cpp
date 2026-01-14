#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n, p;
vector<int> v;

void init() {
	v.clear();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		init();
		cin >> n >> p;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		int rst = p;
		int l = 0;
		for (int r = 0; r < n; r++)
		{
			while (l <= r) {
				int days = v[r] - v[l] + 1;
				int studied = r - l + 1;
				int space = days - studied;

				if (space <= p) break;
				l++;
			}
			int days = v[r] - v[l] + 1;
			int studied = r - l + 1;
			int space = days - studied;

			int len = days + (p - space);
			rst = max(len, rst);
		}

		cout << "#" << tc + 1 << " " << rst << "\n";
	}

	return 0;
}