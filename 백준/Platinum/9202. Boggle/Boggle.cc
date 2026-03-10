#include <iostream>
#include <string>

using namespace std;

struct node
{
	int child[26];
	bool is_end;
	int hit_board_id;
};

node pool[2500000];
int pool_cnt;
int root;

int current_board_id;

inline int new_node() {
	int idx = pool_cnt++;
	for (int i = 0; i < 26; i++)
	{
		pool[idx].child[i] = -1;
	}
	pool[idx].is_end = false;
	pool[idx].hit_board_id = -1;
	return idx;
}

void trie_init() {
	pool_cnt = 0;
	root = new_node();
}

void insert(const string& s) {
	int cur = root;
	for (auto c : s) {
		int idx = c - 'A';
		if (pool[cur].child[idx] == -1) pool[cur].child[idx] = new_node();
		cur = pool[cur].child[idx];
	}
	pool[cur].is_end = true;
}

int w, b;

// 설정 변수
int word_cnt;
int max_point;
string longest_word;
int longest_len;

char boggle[4][4];
bool visited[4][4];

void init() {
	word_cnt = 0;
	max_point = 0;
	longest_word = "";
	longest_len = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			visited[i][j] = false;
		}
	}
}

bool inRange(int y, int x) {
	if (y < 0 || x < 0 || y >= 4 || x >= 4) {
		return false;
	}
	return true;
}
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

string temp;
// 이미 체크 된 단어 인지 확인
void dfs(int r, int c, int cur, int len, string s) {
	if (pool[cur].is_end && pool[cur].hit_board_id != current_board_id) {
		pool[cur].hit_board_id = current_board_id;
		word_cnt++;

		if (len == 3 || len == 4) max_point += 1;
		else if (len == 5) max_point += 2;
		else if (len == 6) max_point += 3;
		else if (len == 7) max_point += 5;
		else if (len == 8) max_point += 11;
		
		if (longest_len <= len) {
			if (longest_len == len) {
				// 사전순 비교
				if (s < longest_word) {
					longest_len = len;
					longest_word = s;
				}
			}
			else {
				longest_len = len;
				longest_word = s;
			}
		}
	}

	if (len == 8) return;

	for (int i = 0; i < 8; i++)
	{
		int ny = r + dy[i];
		int nx = c + dx[i];

		if (!inRange(ny, nx)) continue;
		if (visited[ny][nx]) continue;
		int idx = boggle[ny][nx] - 'A';
		if (pool[cur].child[idx] != -1) {
			visited[ny][nx] = true;
			dfs(ny, nx, pool[cur].child[idx], len + 1, s + boggle[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	trie_init();

	cin >> w;

	for (int i = 0; i < w; i++)
	{
		string s;
		cin >> s;

		insert(s);
	}

	cin >> b;
	for (int i = 0; i < b; i++)
	{
		// 각 testcase마다 초기화
		current_board_id = i + 1;
		init();

		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> boggle[j][k];
			}
		}
		
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int idx = boggle[j][k] - 'A';
				if (pool[root].child[idx] != -1) {
					visited[j][k] = true;
					temp += boggle[j][k];
					dfs(j, k, pool[root].child[idx], 1, temp);
					temp = "";
					visited[j][k] = false;
				}
			}
		}

		cout << max_point << " " << longest_word << " " << word_cnt << "\n";
	}

	return 0;
}