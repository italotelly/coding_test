#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int T, M, A;
int moveA[101], moveB[101];
int dy[] = { 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, 1, 0, -1 };

struct BC {
	int x, y, c, p;
};

vector<BC> chargers;

int getMaxCharge(pair<int, int> A, pair<int, int> B) {
	vector<int> a_list, b_list;

	for (int i = 0; i < chargers.size(); i++) {
		int distA = abs(A.first - chargers[i].y) + abs(A.second - chargers[i].x);
		int distB = abs(B.first - chargers[i].y) + abs(B.second - chargers[i].x);
		if (distA <= chargers[i].c) a_list.push_back(i);
		if (distB <= chargers[i].c) b_list.push_back(i);
	}

	int max_charge = 0;
	for (int i = 0; i < a_list.size(); i++) {
		for (int j = 0; j < b_list.size(); j++) {
			int ai = a_list[i];
			int bi = b_list[j];
			if (ai == bi)
				max_charge = max(max_charge, chargers[ai].p / 2 + chargers[bi].p / 2);
			else
				max_charge = max(max_charge, chargers[ai].p + chargers[bi].p);
		}
	}

	if (a_list.empty()) {
		for (int j = 0; j < b_list.size(); j++)
			max_charge = max(max_charge, chargers[b_list[j]].p);
	}
	if (b_list.empty()) {
		for (int i = 0; i < a_list.size(); i++)
			max_charge = max(max_charge, chargers[a_list[i]].p);
	}

	return max_charge;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> A;

		for (int i = 0; i < M; i++) cin >> moveA[i];
		for (int i = 0; i < M; i++) cin >> moveB[i];

		chargers.clear();
		for (int i = 0; i < A; i++) {
			int x, y, c, p;
			cin >> x >> y >> c >> p;
			chargers.push_back({ x - 1, y - 1, c, p });
		}

		pair<int, int> posA = { 0, 0 };
		pair<int, int> posB = { 9, 9 };

		int total = getMaxCharge(posA, posB);

		for (int i = 0; i < M; i++) {
			posA.first += dy[moveA[i]];
			posA.second += dx[moveA[i]];
			posB.first += dy[moveB[i]];
			posB.second += dx[moveB[i]];
			total += getMaxCharge(posA, posB);
		}

		cout << "#" << tc << " " << total << "\n";
	}

	return 0;
}
