#include <iostream>
#include <vector>

#define MAX_CNT 1000000

using namespace std;

int n;
vector<int> tree(MAX_CNT * 4 + 5);

void update(int idx, int s, int e, int pos, int val) {
	if (s == e) {
		tree[idx] += val;
		return;
	}

	int mid = (s + e) / 2;
	if(pos <= mid) update(idx * 2, s, mid, pos, val);
	else update(idx * 2 + 1, mid + 1, e, pos, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int get(int idx, int s, int e, int x) {
	if (s == e) return s;

	int mid = (s + e) / 2;
	if (x <= tree[idx * 2]) return get(idx * 2, s, mid, x);
	else return get(idx * 2 + 1, mid + 1, e, x - tree[idx * 2]);
}

int main() { 

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;

		cin >> a;

		if (a == 1) {
			cin >> b;
			c = get(1, 1, MAX_CNT, b);
			cout << c << "\n";
			update(1, 1, MAX_CNT, c, -1);
		}
		else if(a == 2) {
			cin >> b >> c;
			update(1, 1, MAX_CNT, b, c);
		}
	}

	return 0;
}