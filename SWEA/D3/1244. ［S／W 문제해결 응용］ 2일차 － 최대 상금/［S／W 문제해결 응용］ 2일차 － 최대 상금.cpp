#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int answer;
unordered_set<string> visited[11];  // 방문 체크용 (depth마다)

void dfs(string num, int depth, int changeCount) {
    if (depth == changeCount) {
        answer = max(answer, stoi(num));
        return;
    }

    // 이미 본 조합이면 스킵
    if (visited[depth].count(num)) return;
    visited[depth].insert(num);

    for (int i = 0; i < num.size(); i++) {
        for (int j = i + 1; j < num.size(); j++) {
            swap(num[i], num[j]);
            dfs(num, depth + 1, changeCount);
            swap(num[i], num[j]);  // backtrack
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; tc++) {
        string num;
        int change;
        cin >> num >> change;

        answer = 0;
        for (int i = 0; i <= change; i++) visited[i].clear();  // visited 초기화
        dfs(num, 0, change);

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}
