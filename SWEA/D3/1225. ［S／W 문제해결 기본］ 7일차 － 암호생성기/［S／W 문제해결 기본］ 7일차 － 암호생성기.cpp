#include <iostream>
#include <queue>

using namespace std;

// 암호생성기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> q1;
    int num;

    for (int i = 1; i <= 10; i++)
    {
        cin >> i;
        cout << "#" << i << " ";

        for (int j = 0; j < 8; j++)
        {
            cin >> num;
            q1.push(num);
        }

        int cnt = 1;
        while (q1.back() > 0)
        {
            if (cnt > 5)
            {
                cnt = 1;
            }
            if ((q1.front() - cnt) > 0)
            {
                q1.push(q1.front() - cnt);
            }
            else
            {
                q1.push(0);
                q1.pop();
                break;
            }
            q1.pop();
            cnt++;
        }

        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
        cout << "\n";
    }
    return 0;
}
