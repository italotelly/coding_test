#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

struct node
{
	string name;
	node* prev = nullptr;
	int al_num = 1;
	int ph_num = 0;
	map<string, node*> al;
	set<string> ph;
}node_pool[100005];

int node_cnt;

int N;

node* root;
node* pwd;

inline node* new_node(string s) {
	node* n = &node_pool[node_cnt];
	n->name = s;
	node_cnt++;
	return n;
}

inline void push_up(node* cur, int da, int dp) {
	while (cur) {
		cur->al_num += da;
		cur->ph_num += dp;
		cur = cur->prev;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	root = new_node("album");
	pwd = root;
	string s1, s2;
	for (int i = 0; i < N; i++)
	{
		cin >> s1;

		if (s1[0] == 'm') {
			cin >> s2;
			if (pwd->al.find(s2) != pwd->al.end()) {
				cout << "duplicated album name\n";
			}
			else {
				node* n = new_node(s2);
				n->prev = pwd;
				pwd->al.insert({s2, n});
				push_up(pwd, 1, 0);
			}
		}
		else if (s1[0] == 'r') {
			int al_cnt = 0;
			int ph_cnt = 0;
			
			cin >> s2;

			if (s2 == "-1") {
				if (pwd->al.size()) {
					auto it = pwd->al.begin();
					al_cnt = (it->second->al_num);
					ph_cnt = (it->second->ph_num);
					push_up(pwd, -al_cnt, -ph_cnt);
					it->second->al.clear();
					it->second->ph.clear();
					it->second->prev = nullptr;
					pwd->al.erase(it);
				}
			}
			else if (s2 == "0") {
				al_cnt = pwd->al_num - 1;
				ph_cnt = pwd->ph_num - pwd->ph.size();
				push_up(pwd, -al_cnt, -ph_cnt);
				pwd->al.clear();
				pwd->al.clear();
			}
			else if (s2 == "1") {
				if (pwd->al.size()) {
					auto it = pwd->al.end();
					it--;
					al_cnt = (it->second->al_num);
					ph_cnt = (it->second->ph_num);
					push_up(pwd, -al_cnt, -ph_cnt);
					it->second->al.clear();
					it->second->ph.clear();
					it->second->prev = nullptr;
					pwd->al.erase(it);
				}
			}
			else {
				auto it = pwd->al.find(s2);
				if (it != pwd->al.end()) {
					al_cnt = (it->second->al_num);
					ph_cnt = (it->second->ph_num);
					push_up(pwd, -al_cnt, -ph_cnt);
					it->second->al.clear();
					it->second->ph.clear();
					it->second->prev = nullptr;
					pwd->al.erase(it);
				}
			}
			cout << al_cnt << " " << ph_cnt << "\n";
		}
		else if (s1[0] == 'i') {
			cin >> s2;
			auto it = pwd->ph.find(s2);
			if (it != pwd->ph.end()) {
				cout << "duplicated photo name\n";
			}
			else {
				pwd->ph.insert(s2);
				push_up(pwd, 0, 1);
			}
		}
		else if (s1[0] == 'd') {
			int ph_cnt = 0;
			cin >> s2;
			if (s2 == "-1") {
				if (pwd->ph.size()) {
					auto it = pwd->ph.begin();
					push_up(pwd, 0, -1);
					pwd->ph.erase(it);
					ph_cnt++;
				}
			}
			else if (s2 == "0") {
				ph_cnt = pwd->ph.size();
				push_up(pwd, 0, -ph_cnt);
				pwd->ph.clear();
			}
			else if (s2 == "1") {
				if (pwd->ph.size()) {
					auto it = pwd->ph.end();
					it--;
					push_up(pwd, 0, -1);
					pwd->ph.erase(it);
					ph_cnt++;
				}
			}
			else {
				auto it = pwd->ph.find(s2);
				if (it != pwd->ph.end()) {
					push_up(pwd, 0, -1);
					pwd->ph.erase(it);
					ph_cnt++;
				}
			}
			cout << ph_cnt << "\n";
		}
		else if (s1[0] == 'c') {
			cin >> s2;
			if (s2 == "..") {
				if (root == pwd) {
					cout << pwd->name << "\n";
					continue;
				}
				pwd = pwd->prev;
				cout << pwd->name << "\n";
			}
			else if (s2 == "/") {
				pwd = root;
				cout << pwd->name << "\n";
			}
			else {
				auto it = pwd->al.find(s2);
				if (it != pwd->al.end()) {
					pwd = it->second;
				}
				cout << pwd->name << "\n";
			}
		}
	}

	return 0;
}