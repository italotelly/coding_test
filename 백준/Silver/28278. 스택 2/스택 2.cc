#include <iostream>
#include <stack>

using namespace std;

// 스택 2
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    stack<int> S;

    int num1 = 0;
    int num2 = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num1;
        switch (num1)
        {
        case 1:
            cin >> num2;
            S.push(num2);
            break;
        case 2:
            if (S.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << S.top() << "\n";
                S.pop();
            }
            break;
        case 3:
            cout << S.size() << "\n";
            break;
        case 4:
            if (S.empty() == 1)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
            break;
        case 5:
            if (S.empty() == 1)
            {
                cout << "-1\n";
            }
            else
            {
                cout << S.top() << "\n";
            }
            break;
        default:
            break;
        }
    }

    return 0;
}