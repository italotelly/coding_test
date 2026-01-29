#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int C, N;
int Q;

struct node
{
	node* child[26];
	bool is_end;
}pool[4000005];

int pool_cnt;
node* root;

unordered_set<string> nickname;

inline node* new_node() {
	node* n = &pool[pool_cnt++];
	for (int i = 0; i < 26; i++)
	{
		n->child[i] = nullptr;
	}
	n->is_end = false;
	return n;
}

void init() {
	pool_cnt = 0;
	root = new_node();
}

void insert(string& s) {
	node* cur = root;
	for (char& c : s) {
		int idx = c - 'a';
		if (cur->child[idx] == nullptr) cur->child[idx] = new_node();
		cur = cur->child[idx];
	}
	cur->is_end = true;
}

bool find(string& s) {
	bool flag1 = false;
	bool flag2 = false;
	node* cur = root;
	int i = 0;
	for (char&c : s) {
		int idx = c - 'a';
		if (cur->child[idx] == nullptr) return false;
		
		cur = cur->child[idx];
		i++;
		
		if (cur->is_end) {
			if (i < s.size()) {
				const string temp = s.substr(i);
				if (nickname.find(temp) != nickname.end()) return true;
			}
		}
	}

	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> C >> N;

	init();

	string s;
	for (int i = 0; i < C; i++)
	{
		cin >> s;
		insert(s);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		nickname.insert(s);
	}

	cin >> Q;

	bool rst = 0;
	for (int i = 0; i < Q; i++)
	{
		cin >> s;
		rst = find(s);
		if (rst) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}