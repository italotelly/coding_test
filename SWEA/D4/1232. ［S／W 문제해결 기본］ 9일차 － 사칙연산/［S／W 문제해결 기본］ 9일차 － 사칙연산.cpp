#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// 트리 노드 구조체
struct Node {
    string val;
    int left = 0;
    int right = 0;
};

Node tree[1001];

// 후위 순회 방식 계산 함수
int evaluate(int idx) {
    if (tree[idx].left == 0 && tree[idx].right == 0) {
        return stoi(tree[idx].val);  // 리프 노드면 숫자 반환
    }

    int leftVal = evaluate(tree[idx].left);
    int rightVal = evaluate(tree[idx].right);

    if (tree[idx].val == "+") return leftVal + rightVal;
    if (tree[idx].val == "-") return leftVal - rightVal;
    if (tree[idx].val == "*") return leftVal * rightVal;
    if (tree[idx].val == "/") return leftVal / rightVal;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; ++tc) {
        int N;
        cin >> N;
        cin.ignore();

        // 트리 초기화
        for (int i = 0; i <= N; ++i) {
            tree[i] = Node();  // 초기화
        }

        // 입력
        for (int i = 0; i < N; ++i) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            int idx;
            ss >> idx;
            ss >> tree[idx].val;

            if (tree[idx].val == "+" || tree[idx].val == "-" ||
                tree[idx].val == "*" || tree[idx].val == "/") {
                ss >> tree[idx].left >> tree[idx].right;
            }
        }

        int result = evaluate(1);  // 항상 루트 노드는 1번
        cout << "#" << tc << " " << result << "\n";
    }

    return 0;
}
