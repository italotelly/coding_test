#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct node
{
	node* child[26];
	int sub_cnt;
	bool is_end;
}pool[800005];

int pool_cnt;
node* root;
int cnt;

inline node* new_node() {
	node* n = &pool[pool_cnt++];
	for (int i = 0; i < 26; i++)
	{
		n->child[i] = nullptr;
	}
	n->sub_cnt = 0;
	n->is_end = false;
	return n;
}

void init() {
	pool_cnt = 0;
	root = new_node();
	cnt = 0;
}

void insert(string& s) {
	node* cur = root;
	for (char& c : s) {
		int idx = c - 'a';
		if (cur->child[idx] == nullptr) cur->child[idx] = new_node();
		cur->sub_cnt += 1;
		cur = cur->child[idx];
	}
	cur->sub_cnt += 1;
	cur->is_end = true;
}

int find(string& s) {
	double rst = 1;
	node* now = root;
	for (char& c : s) {
		int idx = c - 'a';
		if (now->sub_cnt != now->child[idx]->sub_cnt && now != root) rst++;
		now = now->child[idx];
	}
	return rst;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n) {
		init();
		vector<string> word_list;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			word_list.push_back(s);
			insert(s);
		}
		for (int i = 0; i < n; i++)
		{
			s = word_list[i];
			cnt += find(s);
		}
		cout << fixed << setprecision(2);
		cout << round(((double)cnt / (double)n) * 100) / 100 << "\n";
	}

	return 0;
}