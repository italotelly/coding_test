#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> tree;

void init(int idx, int s, int e) {

	if (s == e) {
		tree[idx] = v[s];
		return;
	}
	int mid = (s + e) / 2;
	init(idx * 2, s, mid);
	init(idx * 2 + 1, mid + 1, e);

	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int get(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 21e8;
	if (ts <= s && e <= te) return tree[idx];

	int mid = (s + e) / 2;
	int a = get(idx * 2, s, mid, ts, te);
	int b = get(idx * 2 + 1, mid + 1, e, ts, te);

	return min(a, b);
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	v.resize(N + 1);
	tree.resize(N * 4 + 5);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	init(1, 1, N);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << get(1, 1, N, a, b) << "\n";
	}

	return 0;
}