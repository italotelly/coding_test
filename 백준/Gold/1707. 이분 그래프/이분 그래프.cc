#include <iostream>
#include <queue>

using namespace std;

int K, V, E;

struct node
{
	int num;
	node* nxt;
};

node head[20005];
node pool[200000 * 2 + 5];
int pcnt;

int color[20005];

bool rst = 1;

void init() {
	pcnt = 0;
	rst = 1;
	for (int i = 1; i <= V; i++)
	{
		head[i].nxt = nullptr;
		color[i] = 0;
	}
}

inline void add(int u, int v) {
	pool[pcnt].num = v;
	pool[pcnt].nxt = head[u].nxt;
	head[u].nxt = &pool[pcnt];
	pcnt++;

	pool[pcnt].num = u;
	pool[pcnt].nxt = head[v].nxt;
	head[v].nxt = &pool[pcnt];
	pcnt++;
}

bool bfs_chk(int st) {
	queue<int> q;
	color[st] = 1;
	q.push(st);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (node* p = head[now].nxt; p; p = p->nxt)
		{
			int v = p->num;

			if (color[v] == 0) {
				color[v] = -color[now];
				q.push(v);
			}
			else if (color[v] == color[now]) return false;
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;

		init();

		for (int j = 0; j < E; j++)
		{
			int a, b;
			cin >> a >> b;
			add(a, b);
		}

		for (int j = 0; j < V; j++)
		{
			if (color[j] == 0) {
				if (!bfs_chk(j)) {
					rst = false;
					break;
				}
			}
		}
		cout << (rst ? "YES\n" : "NO\n");
	}

	return 0;
}