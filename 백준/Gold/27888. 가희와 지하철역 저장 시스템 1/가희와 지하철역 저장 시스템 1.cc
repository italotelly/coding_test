#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int n, r;
unordered_map<string, int> stationID;
unordered_map<int, int> idBIT;
unordered_map<string, int> feataddr;
int rst[512];
int feat_cnt;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		stationID.insert({ s, i });
		idBIT.insert({ i, (0 << 9) });
	}
	rst[0] = n;
	cin >> r;

	char a;
	for (int i = 0; i < r; i++)
	{
		cin >> a;

		if (a == 'U') {
			cin >> s;

			auto it = stationID.find(s);
			if (it == stationID.end()) continue;

			cin >> s;
			vector<string> v;
			int st = 0;
			int en = 0;
			while (true) {
				if (s[en] == ',' || s[en] == '\0') {
					v.push_back(s.substr(st, en - st));
					st = en + 1;
				}
				if (s[en] == '\0') break;
				en++;
			}
			int bit = 0 << 9;
			for (int i = 0; i < v.size(); i++)
			{
				if (feataddr.find(v[i]) == feataddr.end()) feataddr.insert({ v[i], feat_cnt++ });
				bit += (1 << feataddr[v[i]]);
			}
			// 해당 아이디의 비트마스크가 없는 경우
			if (idBIT.find(it->second) == idBIT.end()) {
				idBIT.insert({ it->second, bit });
				rst[bit]++;
			}
			// 해당 아이디의 비트마스크가 있는 경우
			else {
				rst[idBIT[it->second]]--;
				idBIT[it->second] = bit;
				rst[bit]++;
			}
		}
		else if (a == 'G') {
			cin >> s;
			vector<string> v;
			int st = 0;
			int en = 0;
			while (true) {
				if (s[en] == ',' || s[en] == '\0') {
					v.push_back(s.substr(st, en - st));
					st = en + 1;
				}
				if (s[en] == '\0') break;
				en++;
			}
			int bit = 0 << 9;
			int flag = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (feataddr.find(v[i]) == feataddr.end()) {
					cout << "0\n";
					flag = 1;
					break;
				}
				bit += (1 << feataddr[v[i]]);
			}
			if (flag) continue;
			int result = 0;
			for (int i = 0; i < 512; i++)
			{
				if ((i & bit) == bit) result += rst[i];
			}
			cout << result << "\n";
		}
	}
	return 0;
}