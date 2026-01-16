#include <iostream>
#include <string>

#define MAX_NODES 5000005

using namespace std;

int N, M;
int rst;

struct Node
{
	Node* child[26];
	bool is_end;
};

Node pool[MAX_NODES];
int cnt;
Node* root;

inline Node* newNode() {
	Node* n = &pool[cnt++];
	for (int i = 0; i < 26; i++)
	{
		n->child[i] = nullptr;
	}
	n->is_end = false;
	return n;
}

void init() {
	cnt = 0;
	root = newNode();
}

void insert(const string& s) {
	Node* cur = root;
	for (char c : s)
	{
		int idx = c - 'a';
		if (cur->child[idx] == nullptr) cur->child[idx] = newNode();
		cur = cur->child[idx];
	}
	cur->is_end = true;
}

void find(const string& s) {
	Node* cur = root;
	for (char c : s)
	{
		int idx = c - 'a';
		if (cur->child[idx] == nullptr) return;
		cur = cur->child[idx];
	}
	rst++;
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	init();

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		insert(s);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		find(s);
	}

	cout << rst << "\n";

	return 0;
}