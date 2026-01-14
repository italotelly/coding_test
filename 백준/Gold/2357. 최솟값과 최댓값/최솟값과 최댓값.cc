#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> max_tree;
vector<int> min_tree;

// 세그먼트 트리 초기화
void init(int node, int left, int right) {
	if (left == right){
		max_tree[node] = v[left];
		min_tree[node] = v[left];
		return;
	}
	int mid = (left + right) / 2;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);

	max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
}

int get_max(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 0;
	if (ts <= s && e <= te) return max_tree[idx];

	int mid = (s + e) / 2;
	int s_max = get_max(idx * 2, s, mid, ts, te);
	int e_max = get_max(idx * 2 + 1, mid + 1, e, ts, te);

	return max(s_max, e_max);
}
int get_min(int idx, int s, int e, int ts, int te) {
	if (s > te || e < ts) return 21e8;
	if (ts <= s && e <= te) return min_tree[idx];

	int mid = (s + e) / 2;
	int s_min = get_min(idx * 2, s, mid, ts, te);
	int e_min = get_min(idx * 2 + 1, mid + 1, e, ts, te);

	return min(s_min, e_min);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	v.resize(N);
	max_tree.resize(4 * N + 5);
	min_tree.resize(4 * N + 5);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	init(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << get_min(1, 0, N - 1, a - 1, b - 1) << " " << get_max(1, 0, N - 1, a - 1, b - 1) << "\n";
	}

	return 0;
}