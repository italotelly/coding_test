#include <iostream>
#include <deque>

using namespace std;

// 덱 2
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int x;
    int num;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (x == 1)
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (x == 2)
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (x == 3)
        {
            if (dq.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (x == 4)
        {
            if (dq.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (x == 5)
        {
            cout << dq.size() << "\n";
        }
        else if (x == 6)
        {
            if (dq.empty() == 1)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (x == 7)
        {
            if (dq.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.front() << "\n";
            }
        }
        else if (x == 8)
        {
            if (dq.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << dq.back() << "\n";
            }
        }
        else
        {
            cout << "rewrite the command\n"
                 << "it will skip the one chance\n";
            continue;
        }
    }

    return 0; // 정상종료
}