#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<string, int> m;
vector<string> v;
int flag;

void init() {
	m.clear();
	v.clear();
	flag = 0;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		init();
		int n;
		cin >> n;
		string x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
			m[x] = 1;
		}
		for (int i = 0; i < v.size(); i++)
		{
			string s;
			for (int j = 0; j < v[i].size() - 1; j++)
			{
				s += v[i][j];
				if (m.find(s) != m.end()) flag = 1;
			}
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}