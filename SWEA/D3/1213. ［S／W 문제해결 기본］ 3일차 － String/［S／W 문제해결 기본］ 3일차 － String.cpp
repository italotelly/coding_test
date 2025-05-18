#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; ++tc) {
		int test_case_num;
		cin >> test_case_num;

		string pattern, text;
		cin >> pattern >> text;

		int cnt = 0;
		int p_len = pattern.length();
		int t_len = text.length();

		for (int i = 0; i <= t_len - p_len; ++i) {
			if (text.substr(i, p_len) == pattern) {
				cnt++;
			}
		}

		cout << "#" << test_case_num << " " << cnt << "\n";
	}

	return 0;
}
