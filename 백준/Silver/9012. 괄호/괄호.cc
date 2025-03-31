#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    stack<char> s1;
    stack<char> s2;
    string p;

    for (int i = 0; i < T; i++)
    {
        cin >> p;
        while (s1.empty() == 0)
        {
            s1.pop();
        }
        while (s2.empty() == 0)
        {
            s2.pop();
        }
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == '(')
            {
                s1.push(p[j]);
            }
            else
            {
                if (s1.empty() == 1)
                {
                    s2.push(p[j]);
                    break;
                }
                else
                {
                    s1.pop();
                }
            }
        }
        if (s1.empty() == 1 && s2.empty() == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}