#include <iostream>
#include <set>;

using namespace std;

int P;
int tc;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> P;

	for (int i = 0; i < P; i++)
	{
		cin >> tc;
		set<int> s;
		int sum = 0;
		int num;
		for (int j = 0; j < 20; j++)
		{
			cin >> num;
			if (j == 0) {
				s.insert(num);
				continue;
			}
			int cnt = 0;
			auto it = s.begin();
			while (it != s.end() && *it < num) {
				cnt++; it++;
			}
			sum += (s.size() - cnt);
			s.insert(num);
		}
		cout << tc << " " << sum << "\n";
	}

	return 0;
}