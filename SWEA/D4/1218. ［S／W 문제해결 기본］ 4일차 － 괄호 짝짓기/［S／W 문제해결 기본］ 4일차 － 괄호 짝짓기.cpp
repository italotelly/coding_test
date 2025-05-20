#include <iostream>
#include <string>
#include <stack>

using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	char sign;
	stack<char> a, b, c, d;
	int len;
	int chk;

	for (int i = 1; i <= 10; i++) {
		cin >> len;
		chk = 0;
		cin >> s;
		for (int j = 0;j < len;j++) {
			sign = s[j];

			if (sign == '(') {
				a.push(sign);
			}
			else if (sign == ')') {
				if (a.empty()) {
					chk = 1;
					break;
				}
				else if (a.top() == '(') {
					a.pop();
				}
				else {
					chk = 1;
				}
			}
			else if (sign == '[') {
				b.push(sign);
			}
			else if (sign == ']') {
				if (b.empty()) {
					chk = 1;
					break;
				}
				else if (b.top() == '[') {
					b.pop();
				}
				else {
					chk = 1;
				}
			}
			else if (sign == '{') {
				c.push(sign);
			}
			else if (sign == '}') {
				if (c.empty()) {
					chk = 1;
					break;
				}
				else if (c.top() == '{') {
					c.pop();
				}
				else {
					chk = 1;
				}
			}
			else if (sign == '<') {
				d.push(sign);
			}
			else if (sign == '>') {
				if (d.empty()) {
					chk = 1;
					break;
				}
				else if (d.top() == '<') {
					d.pop();
				}
				else {
					chk = 1;
				}
			}
		}

		if (a.empty() && b.empty() && c.empty() && d.empty() && chk == 0) {
			// 출력
			cout << "#" << i << " 1" << "\n";
		}
		else {
			// 출력
			cout << "#" << i << " 0" << "\n";
			while (!a.empty()) {
				a.pop();
			}
			while (!b.empty()) {
				b.pop();
			}
			while (!c.empty()) {
				c.pop();
			}
			while (!d.empty()) {
				d.pop();
			}
		}
	}

	return 0;
}