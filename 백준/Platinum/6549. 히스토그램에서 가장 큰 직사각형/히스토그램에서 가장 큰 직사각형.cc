#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n;

int ary[100005];
int tree[400005];

void init_seg(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = s;
		return;
	}
	int mid = (s + e) / 2;
	init_seg(idx * 2, s, mid);
	init_seg(idx * 2 + 1, mid + 1, e);

	if (ary[tree[idx * 2]] <= ary[tree[idx * 2 + 1]]) {
		tree[idx] = tree[idx * 2];
	}
	else {
		tree[idx] = tree[idx * 2 + 1];
	}
}

int get_seg(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return -1;
	if (ts <= s && e <= te) return tree[idx];

	int mid = (s + e) / 2;
	int a = get_seg(idx * 2, s, mid, ts, te);
	int b = get_seg(idx * 2 + 1, mid + 1, e, ts, te);

	if (a == -1) return b;
	if (b == -1) return a;

	if (ary[a] <= ary[b]) return a;
	else return b;
}

ll solve(int s, int e) {
	if (s > e) return 0;

	int min_idx = get_seg(1, 1, n, s, e);

	ll area = (ll)ary[min_idx] * (e - s + 1);

	ll a = solve(s, min_idx - 1);
	ll b = solve(min_idx + 1, e);

	return max(area, max(a, b));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n) {
		if (n == 0) break;

		for (int i = 1; i <= n; i++)
		{
			cin >> ary[i];
		}
		init_seg(1, 1, n);

		cout << solve(1, n) << "\n";
	}

	return 0;
}