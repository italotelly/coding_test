#include <iostream>
#include <queue>

using namespace std;

// 요세푸스 문제 0
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        q.push(i + 1);
    }

    cout << "<";
    while (q.empty() != 1)
    {
        if (q.size() == 1)
        {
            cout << q.front() << ">";
            break;
        }
        for (int i = 0; i < K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }

    return 0; // 정상종료
}