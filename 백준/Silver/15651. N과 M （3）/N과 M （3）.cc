#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> path;

void backtrack(int start)
{
    if (path.size() == M)
    { // M개의 수를 선택하면 출력
        for (int num : path)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    { // 현재 숫자보다 큰 숫자만 선택
        path.push_back(i);
        backtrack(i + 1); // 다음 숫자는 i+1부터 선택
        path.pop_back();  // 백트래킹: 마지막 원소 제거
    }
}

int main()
{
    cin >> N >> M;
    backtrack(1); // 1부터 시작
    return 0;
}
