#include<iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;

	for (int i = 0; i < 10; i++) {
		cin >> TC;

		int ary[100][100] = { 0 };

		// 배열 input
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				cin >> ary[j][k];
			}
		}

		int min_cnt = 10001;
		int min_k = 0;
		int cnt = 0;

		// 거꾸로 시작, 모든 경우에 대해서 cnt 비교
		for (int k = 0; k < 100; k++) {
			int j = 99;
			int mem_k = k;
			// 도착지가 1이면 시작
			if (ary[j][k]) {
				cnt = 0;
				while (j>0) {
					// 좌
					if (k - 1 >= 0 && ary[j][k - 1]) {
						while (k - 1 >= 0 && ary[j][k - 1]) {
							k--;
							cnt++;
						}
					}
					// 우
					else if (k + 1 < 100 && ary[j][k + 1]) {
						while (k + 1 < 100 && ary[j][k + 1]) {
							k++;
							cnt++;
						}
					}
					j--;
					cnt++;
				}
				if (min_cnt > cnt) {
					min_cnt = cnt;
					min_k = k;
				}
				else if (min_cnt == cnt && min_k < k) {
					min_k = k;
				}
				k = mem_k;
			}

		}

		// 출력
		cout << "#" << TC << " " << min_k <<"\n";

	}


	return 0;
}