#include <iostream>

using namespace  std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int len;

	for (int i = 1; i <= 10; i++) {
		cin >> len;
		char ary[8][8] = { 0 };

		// 글자판
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				cin >> ary[j][k];
			}
		}

		int cnt = 0;
		int r_cnt = 0;

		// row에서 회문 찾기
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < (8 - len + 1); k++) {
				int temp_ks = k;
				int temp_ke = k;
				r_cnt = 0;
				while (temp_ks < temp_ke+len-1) {
					if (ary[j][temp_ks] == ary[j][temp_ke+len-1]) {
						r_cnt++;
					}
					temp_ks++;
					temp_ke--;
				}
				if (r_cnt == len / 2) {
					cnt++;
				}
			}
		}

		int c_cnt = 0;
		// col에서 회문 찾기
		for (int k = 0; k < 8; k++) {
			for (int j = 0; j < (8 - len + 1); j++) {
				int temp_js = j;
				int temp_je = j;
				c_cnt = 0;
				while (temp_js < temp_je + len - 1) {
					if (ary[temp_js][k] == ary[temp_je + len - 1][k]) {
						c_cnt++;
					}
					temp_js++;
					temp_je--;
				}
				if (c_cnt == len / 2) {
					cnt++;
				}
			}
		}

		// 출력
		cout << "#" << i << " " << cnt << "\n";
	}

	return 0;
}