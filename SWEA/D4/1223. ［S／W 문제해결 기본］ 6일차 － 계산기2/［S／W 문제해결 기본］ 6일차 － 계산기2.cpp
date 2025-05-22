#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getPriority(char op) {
	if (op == '*') return 2;
	if (op == '+') return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tc = 1; tc <= 10; ++tc) {
		int N;
		string expr;
		cin >> N >> expr;

		string postfix = "";
		stack<char> op;

		for (char ch : expr) {
			if (isdigit(ch)) {
				postfix += ch;
			}
			else if (ch == '+' || ch == '*') {
				while (!op.empty() && getPriority(op.top()) >= getPriority(ch)) {
					postfix += op.top();
					op.pop();
				}
				op.push(ch);
			}
		}
		while (!op.empty()) {
			postfix += op.top();
			op.pop();
		}

		// 2. 후위 계산
		stack<int> num;
		for (char ch : postfix) {
			if (isdigit(ch)) {
				num.push(ch - '0');
			}
			else {
				int b = num.top(); num.pop();
				int a = num.top(); num.pop();
				if (ch == '+') num.push(a + b);
				else if (ch == '*') num.push(a * b);
			}
		}

		cout << "#" << tc << " " << num.top() << "\n";
	}

	return 0;
}
