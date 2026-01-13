#include <iostream>
#include <string>

using namespace std;

int T;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	string s;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> s;

		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'O') {
				cnt++;
				sum += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}