#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int len;

	for (int i = 1; i <= 10; i++) {
		cin >> len;
		int ary[100][100] = { 0 };
		int cnt = 0;
		stack<int> s;
		while (!s.empty()) {
			s.pop();
		}

		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				cin >> ary[j][k];
			}
		}

		for (int k = 0; k < 100; k++) {
			while (!s.empty()) {
				s.pop();
			}
			for (int j = 0; j < 100; j++) {
				// 위에서 아래 방향, S가 먼저 들어오게되면 굳이 push할 필요 없음
				if (ary[j][k]==2 && s.empty()) {
					continue;
				}
				// N이 들어오면 push
				else if (ary[j][k] == 1) {
					s.push(ary[j][k]);
				}
				// S가 들어왔는데 stack에 값이 있음
				else if (ary[j][k] == 2 && !s.empty()) {
					if (s.top() == 1) {
						cnt++;
					}
					s.push(ary[j][k]);
				}
			}
		}
		cout << "#" << i << " " << cnt << "\n";
	}

	return 0;
}