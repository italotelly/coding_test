#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPriority(char op) {
	if (op == '(') return 0;
	if (op == '+') return 1;
	if (op == '*') return 2;
	return -1;
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
			else if (ch == '(') {
				op.push(ch);
			}
			else if (ch == ')') {
				while (!op.empty() && op.top() != '(') {
					postfix += op.top();
					op.pop();
				}
				if (!op.empty()) op.pop(); // 여는 괄호 제거
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

		// 2. 후위표기식 계산
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
