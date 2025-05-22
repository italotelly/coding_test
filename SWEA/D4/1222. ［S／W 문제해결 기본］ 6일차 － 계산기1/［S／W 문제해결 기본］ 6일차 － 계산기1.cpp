#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 연산자 우선순위
int priority(char op) {
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
            } else if (ch == '+') {
                while (!op.empty() && priority(op.top()) >= priority(ch)) {
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
        stack<int> num;
        for (char ch : postfix) {
            if (isdigit(ch)) {
                num.push(ch - '0');
            } else if (ch == '+') {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(a + b);
            }
        }

        cout << "#" << tc << " " << num.top() << "\n";
    }

    return 0;
}