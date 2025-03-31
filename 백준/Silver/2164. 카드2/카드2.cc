#include <iostream>
#include <queue>

using namespace std;

// 카드2
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        q.push(i + 1);
    }

    while (true)
    {

        if (q.size() == 1)
        {
            break;
        }
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0; // 정상종료
}