#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> st;
map<int, int> m;

static inline bool has(const map<int, int>& mp, int key) {
	return mp.find(key) != mp.end(); // mp[key] 금지 (삽입됨)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	st[N] = 1;

	int W = 2 * N - 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {

			if (i % 3 == 1) {
				cout << (has(st, j) ? '*' : ' ');
			}
			else if (i % 3 == 2) {
				bool star = has(st, j + 1) || has(st, j - 1);
				cout << (star ? '*' : ' ');
			}
			else {
				if (has(st, j + 2)) {
					cout << "*****";
					if (j + 5 <= W) cout << ' ';

					int center = j + 2;
					if (center - 3 > 0) m[center - 3]++;
					m[center + 3]++;

					j += 5;
				}
				else {
					cout << ' ';
				}
			}
		}

		cout << "\n";

		if (i % 3 == 0) {
			st.clear();
			for (auto &p : m) {
				if (p.second == 1) st[p.first] = 1;
			}
			m.clear();
		}
	}
	return 0;
}
