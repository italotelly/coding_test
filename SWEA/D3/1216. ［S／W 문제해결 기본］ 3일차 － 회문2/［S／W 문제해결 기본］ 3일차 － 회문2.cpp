#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char board[100][100];

bool isPalindromeRow(int row, int start, int len) {
	for (int i = 0; i < len / 2; i++) {
		if (board[row][start + i] != board[row][start + len - 1 - i])
			return false;
	}
	return true;
}

bool isPalindromeCol(int col, int start, int len) {
	for (int i = 0; i < len / 2; i++) {
		if (board[start + i][col] != board[start + len - 1 - i][col])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; ++tc) {
		int T;
		cin >> T;

		// 입력
		for (int i = 0; i < 100; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < 100; j++) {
				board[i][j] = line[j];
			}
		}

		int maxLen = 1;

		// row 검사
		for (int i = 0; i < 100; i++) {
			for (int len = 100; len >= 2; len--) {
				for (int start = 0; start <= 100 - len; start++) {
					if (isPalindromeRow(i, start, len)) {
						maxLen = max(maxLen, len);
						break; // 더 긴 건 이미 찾음
					}
				}
				if (maxLen >= len) break;
			}
		}

		// col 검사
		for (int j = 0; j < 100; j++) {
			for (int len = 100; len >= 2; len--) {
				for (int start = 0; start <= 100 - len; start++) {
					if (isPalindromeCol(j, start, len)) {
						maxLen = max(maxLen, len);
						break;
					}
				}
				if (maxLen >= len) break;
			}
		}

		cout << "#" << T << " " << maxLen << "\n";
	}

	return 0;
}
