#include <iostream>

using namespace std;

int N, M;
int tree[400005];
int lazy[400005];

void update_lazy(int idx, int s, int e) {
	if (lazy[idx] != 0) {
		tree[idx] = (e - s + 1) - tree[idx];
		if (s != e) {
			lazy[idx * 2] ^= 1;
			lazy[idx * 2 + 1] ^= 1;
		}
		lazy[idx] = 0;
	}
}
void update_range(int idx, int s, int e, int ts, int te, int val) {
	update_lazy(idx, s, e);
	if (e < ts || s > te) return;
	if (ts <= s && e <= te) {
		lazy[idx] ^= 1;
		update_lazy(idx, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update_range(idx * 2, s, mid, ts, te, val);
	update_range(idx * 2 + 1, mid + 1, e, ts, te, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int get_seg(int idx, int s, int e, int ts, int te) {
	update_lazy(idx, s, e);
	if (e < ts || s > te) return 0;
	if (ts <= s && e <= te) {
		return tree[idx];
	}

	int mid = (s + e) / 2;
	int a = get_seg(idx * 2, s, mid, ts, te);
	int b = get_seg(idx * 2 + 1, mid + 1, e, ts, te);
	
	return a + b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int o, s, t;
		cin >> o >> s >> t;
		if (o == 0) {
			update_range(1, 1, N, s, t, 1);
		}
		else if (o == 1) {
			cout << get_seg(1, 1, N, s, t) << "\n";
		}
	}

	return 0;
}