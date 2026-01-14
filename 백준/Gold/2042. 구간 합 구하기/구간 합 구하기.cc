#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> v;
vector<ll> tree;

int N, M, K;

void init(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = v[s];
		return;
	}

	int mid = (s + e) / 2;
	init(idx * 2, s, mid);
	init(idx * 2 + 1, mid + 1, e);

	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
void update(int idx, int s, int e, int pos, ll val) {
	if (s == e) {
		tree[idx] = val;
		return;
	}
	int mid = (s + e) / 2;

	if(pos <= mid) update(idx * 2, s, mid, pos, val);
	else update(idx * 2 + 1, mid + 1, e, pos, val);

	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	if (ts <= s && e <= te) return tree[idx];

	int mid = (s + e) / 2;
	ll a = get(idx * 2, s, mid, ts, te);
	ll b = get(idx * 2 + 1, mid + 1, e, ts, te);

	return a + b;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;

	v.resize(N + 1);
	tree.resize(N * 4 + 5);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	init(1, 1, N);

	int a, b;
	ll c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, N, b, c);
		}
		else if (a == 2) {
			cout << get(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}