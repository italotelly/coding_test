#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int T;
string s;
int n;
deque<int> d;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {

		int flag = 0;

		d.clear();

		cin >> s;
		cin >> n;
		string s1;
		cin >> s1;

		vector<int> v;
		for (int i = 1; i < s1.size(); i++)
		{
			if (i == s1.size() - 2) {
				v.push_back(s1[i] - '0');
				int num = 0;
				for (int j = 0; j < v.size(); j++)
				{
					num += (v[j] * (pow(10, v.size() - j - 1)));
				}
				d.push_back(num);
				v.clear();
			}
			if (s1[i] == ',') {
				int num = 0;
				for (int j = 0; j < v.size(); j++)
				{
					num += (v[j] * (pow(10, v.size() - j - 1)));
				}
				d.push_back(num);
				v.clear();
			}
			else {
				v.push_back(s1[i] - '0');
			}
		}

		int r = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R') {
				r = !r;
			}
			else if (s[i] == 'D') {
				if (d.empty()) {
					cout << "error\n";
					flag = 1;
					break;
				}
				if (r == 0) {
					d.pop_front();
				}
				else {
					d.pop_back();
				}
			}
		}

		if (flag == 0) {

			cout << "[";

			if (r == 0) {
				for (int i = 0; i < d.size(); i++)
				{
					if (i == d.size() - 1) {
						cout << d[i];
					}
					else {
						cout << d[i] << ",";
					}
				}
			}
			else {
				for (int i = d.size() - 1; i >= 0; i--)
				{
					if (i == 0) {
						cout << d[i];
					}
					else {
						cout << d[i] << ",";
					}
				}
			}
			cout << "]\n";

		}
	}

	return 0;
}