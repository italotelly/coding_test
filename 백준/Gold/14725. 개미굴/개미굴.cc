#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node
{
	map<string, int> child;
};

static const int MAX_NODES = 200000;
Node pool[MAX_NODES];
int cnt;

int N, K;

int newNode() {
	pool[cnt].child.clear();
	return cnt++;
}

void init() {
	cnt = 0;
	newNode();
}

void insert(vector<string>& s) {
	int cur = 0;
	for (string& ss : s)
	{
		auto it = pool[cur].child.find(ss);
		if (it == pool[cur].child.end()) {
			pool[cur].child[ss] = newNode();
			cur = pool[cur].child[ss];
		}
		else cur = it->second;
	}
}

void dfs(int node, int depth) {
	for (auto &kv : pool[node].child) {
		for (int i = 0; i < depth; i++) cout << "--";
		cout << kv.first << "\n";
		dfs(kv.second, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	init();

	for (int i = 0; i < N; i++)
	{
		cin >> K;
		vector<string> s(K);
		for (int j = 0; j < K; j++)
		{
			cin >> s[j];
		}
		insert(s);
	}

	dfs(0, 0);

	return 0;
}