#include <iostream>

using namespace std;
using ll = long long;

int N, M, K;

ll ary[1000005];
ll tree[4000005];
ll lazy[4000005];

void init_seg(int idx, int s, int e) {
	lazy[idx] = 0;
	if (s == e) {
		tree[idx] = ary[s];
		return;
	}
	int mid = (s + e) / 2;
	init_seg(idx * 2, s, mid);
	init_seg(idx * 2 + 1, mid + 1, e);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
void push_lazy(int idx, int s, int e) {
	if (lazy[idx] == 0) return;

	tree[idx] += lazy[idx] * (e - s + 1);

	if (s != e) {
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}
void update_seg(int idx, int s, int e, int ts, int te, ll val) {
	push_lazy(idx, s, e);
	if (e < ts || s > te) return;
	if (ts <= s && e <= te) {
		lazy[idx] += val;
		push_lazy(idx, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update_seg(idx * 2, s, mid, ts, te, val);
	update_seg(idx * 2 + 1, mid + 1, e, ts, te, val);

	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll get_seg(int idx, int s, int e, int ts, int te) {
	push_lazy(idx, s, e);
	if (e < ts || s > te) return 0;
	if (ts <= s && e <= te) {
		return tree[idx];
	}
	int mid = (s + e) / 2;
	return get_seg(idx * 2, s, mid, ts, te) + get_seg(idx * 2 + 1, mid + 1, e, ts, te);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> ary[i];
	}
	init_seg(1, 1, N);

	int a, b, c;
	ll d;

	for (int i = 0; i < M + K; i++)
	{
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update_seg(1, 1, N, b, c, d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << get_seg(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}