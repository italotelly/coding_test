#include <iostream>
#include <deque>
#include <stack>

using namespace std;

// 도키도키 간식드리미
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;
    int num;

    deque<int> s1;
    stack<int> s2;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        s1.push_back(num);
    }

    int i = 1;
    int final_chk = 1;
    while (i <= N)
    {
        int chk = 0;
        if (s2.empty() == 0 && s2.top() == i)
        {
            s2.pop();
            i++;
            chk = 1;
        }
        while (chk == 0 && s1.empty() != 1)
        {
            if (s1.front() == i)
            {
                s1.pop_front();
                i++;
                chk = 1;
                break;
            }
            else
            {
                s2.push(s1.front());
                s1.pop_front();
            }
        }
        if (chk == 0)
        {
            if (s2.top() == i)
            {
                s2.pop();
                i++;
                chk = 1;
                break;
            }
            else
            {
                final_chk = 0;
                break;
            }
        }
    }

    if (final_chk == 1)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }

    return 0;
}