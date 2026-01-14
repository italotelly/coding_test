#include <iostream>
#include <vector>

#define div 1000000007

using ll = long long;
using namespace std;

int N, M, K;
vector<int> v;
vector<ll> tree;

void init(int idx, int s, int e) {
	if (s == e) {
		tree[idx] = v[s];
		return;
	}
	int mid = (s + e) / 2;
	init(idx * 2, s, mid);
	init(idx * 2 + 1, mid + 1, e);

	tree[idx] = ((tree[idx * 2] * tree[idx * 2 + 1]) % div);
}
void update(int idx, int s, int e, int pos, int val) {
	if (s == e) {
		tree[idx] = val;
		return;
	}

	int mid = (s + e) / 2;

	if (pos <= mid) update(idx * 2, s, mid, pos, val);
	else update(idx*2 + 1, mid + 1, e, pos, val);

	tree[idx] = ((tree[idx * 2] * tree[idx * 2 + 1]) % div);
}
ll get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 1;
	if (ts <= s && e <= te) return tree[idx];

	int mid = (s + e) / 2;
	ll a = get(idx * 2, s, mid, ts, te);
	ll b = get(idx * 2 + 1, mid + 1, e, ts, te);

	return ((a*b) % div);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	v.resize(N + 1);
	tree.resize(N * 4 + 5);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	init(1, 1, N);

	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b >> c;
			update(1, 1, N, b, c);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << get(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}