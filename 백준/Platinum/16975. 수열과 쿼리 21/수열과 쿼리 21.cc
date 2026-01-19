#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, M;
vector<ll> v;
vector<ll> tree;

void update(int idx, int s, int e, int i, int j, ll k) {
	if (s > j || e < i) return;
	if (i <= s && e <= j) {
		tree[idx] += k;
		return;
	}
	int mid = (s + e) / 2;
	update(idx * 2, s, mid, i, j, k);
	update(idx * 2 + 1, mid + 1, e, i, j, k);
}

ll get(int idx, int s, int e, int x, ll sum) {
	sum += tree[idx];
	if (s == e) return v[s] + sum;

	int mid = (s + e) / 2;
	if (x <= mid) return get(idx * 2, s, mid, x, sum);
	else return get(idx * 2 + 1, mid + 1, e, x, sum);
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	v.resize(N + 1);
	tree.resize(N * 4 + 5);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;

		if (a == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update(1, 1, N, b, c, d);
		}
		else if (a == 2) {
			int x;
			cin >> x;
			cout << get(1, 1, N, x, 0) << "\n";
		}
	}

	return 0;
}