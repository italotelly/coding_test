#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int left;
	int right;
};

int N;

vector<edge> v[30];

void pre_dfs(int st) {
	if (st == -1) {
		return;
	}
	cout << (char)('A' + st);
	pre_dfs(v[st][0].left);
	pre_dfs(v[st][0].right);
}
void mid_dfs(int st) {
	if (st == -1) {
		return;
	}
	mid_dfs(v[st][0].left);
	cout << (char)('A' + st);
	mid_dfs(v[st][0].right);
}
void post_dfs(int st) {
	if (st == -1) {
		return;
	}
	post_dfs(v[st][0].left);
	post_dfs(v[st][0].right);
	cout << (char)('A' + st);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		int y, x;
		if (b == '.') {
			y = -1;
		}
		else {
			y = b - 'A';
		}
		if (c == '.') {
			x = -1;
		}
		else {
			x = c - 'A';
		}

		v[(int)(a - 'A')].push_back({y, x});
	}

	pre_dfs(0);
	cout << "\n";
	mid_dfs(0);
	cout << "\n";
	post_dfs(0);

	return 0;
}