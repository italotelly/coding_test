#include <iostream>
#include <queue>
#include <string>

using namespace std;

// 큐 2
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string s;
    int num;

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        cin >> s;

        if (s == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            if (q.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (s == "size")
        {
            cout << q.size() << "\n";
        }
        else if (s == "empty")
        {
            if (q.empty() == 1)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (s == "front")
        {
            if (q.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.front() << "\n";
            }
        }
        else if (s == "back")
        {
            if (q.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << q.back() << "\n";
            }
        }
        else
        {
            cout << "rewrite the command\n"
                 << "it will skip the one chance\n";
            continue;
        }
    }

    return 0;
}