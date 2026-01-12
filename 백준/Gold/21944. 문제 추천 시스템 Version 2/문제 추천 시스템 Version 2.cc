#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>

using namespace std;

int N, M;

int PG[100005];
int PL[100005];

set<pair<int, int>> r1[105];
set<pair<int, int>> r23;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int P, L, G;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> L >> G;
		PG[P] = G;
		PL[P] = L;
		r1[G].insert({ L, P });
		r23.insert({ L, P });
	}

	cin >> M;

	string s;
	int x;
	for (int i = 0; i < M; i++)
	{
		cin >> s;

		if (s == "recommend") {
			cin >> G >> x;
			if (x == 1) {
				cout << prev(r1[G].end())->second << "\n";
			}
			else if (x == -1) {
				cout << r1[G].begin()->second << "\n";
			}
		}
		else if (s == "recommend2") {
			cin >> x;
			if (x == 1) {
				cout << prev(r23.end())->second << "\n";
			}
			else if (x == -1) {
				cout << r23.begin()->second << "\n";
			}
		}
		else if (s == "recommend3") {
			cin >> x >> L;
			if (x == 1) {
				auto it = r23.lower_bound({ L, 0 });
				if (it == r23.end()) {
					cout << "-1\n";
				}
				else {
					cout << it->second << "\n";
				}
			}
			else if (x == -1) {
				auto it = r23.lower_bound({ L, 0 });
				if (it == r23.begin()) {
					cout << "-1\n";
				}
				else {
					it--;
					cout << it->second << "\n";
				}
			}
		}
		else if (s == "add") {
			cin >> P >> L >> G;
			PG[P] = G;
			PL[P] = L;
			r1[G].insert({ L, P });
			r23.insert({ L, P });
		}
		else if (s == "solved") {
			cin >> P;
			G = PG[P];
			L = PL[P];
			r1[G].erase({ L, P });
			r23.erase({ L, P });
		}
	}

	return 0;
}