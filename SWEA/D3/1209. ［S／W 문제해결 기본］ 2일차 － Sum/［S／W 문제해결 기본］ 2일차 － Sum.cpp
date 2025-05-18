#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;
	int sum_row, sum_col, sum_diag;
	int row_max, col_max, diag_max;
	int max_num;

	// 10개의 TC
	for (int i = 1; i <= 10; i++) {
		
		// TC마다 초기화
		int ary[100][100] = { 0 };
		sum_row = 0;
		sum_col = 0;
		sum_diag = 0;
		row_max = 0;
		col_max = 0;
		diag_max = 0;

		max_num = 0;
		
		cin >> TC;

		// ary 값 삽입 및 max col 계산
		for (int j = 0; j < 100; j++) {
			sum_col = 0;
			for (int k = 0; k < 100; k++) {
				cin >> ary[j][k];
				sum_col += ary[j][k];
				col_max = max(col_max, sum_col);

				// 우하향 diag 계산
				if (j == k) {
					sum_diag += ary[j][k];
				}
			}
		}

		diag_max = sum_diag;
		// sum diag 초기화
		sum_diag = 0;

		// max row 계산
		for (int k = 0; k < 100; k++) {
			sum_row = 0;
			for (int j = 0; j < 100; j++) {
				sum_row += ary[j][k];
				row_max = max(row_max, sum_row);

				// 좌하향 diag 계산
				if (j + k == 9) {
					sum_diag += ary[j][k];
				}
			}
		}
		max_num = max(diag_max, sum_diag);
		max_num = max(max_num, row_max);
		max_num = max(max_num, col_max);

		// 출력
		cout << "#" << TC << " " << max_num << "\n";
	}

	return 0;
}