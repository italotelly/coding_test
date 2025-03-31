#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

// 풍선 터뜨리기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    deque<int> dq;
    deque<int> temp;

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        dq.push_back(num);
        temp.push_back(i + 1);
    }

    int it;
    for (int j = 0; j < N; j++)
    {
        if (dq.front() > 0)
        {
            cout << temp.front() << " ";
            it = dq.front();
            dq.pop_front();
            temp.pop_front();
            for (int i = 1; i < it; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                temp.push_back(temp.front());
                temp.pop_front();
            }
        }
        else
        {
            cout << temp.front() << " ";
            it = abs(dq.front());
            dq.pop_front();
            temp.pop_front();
            for (int i = 0; i < it; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                temp.push_front(temp.back());
                temp.pop_back();
            }
        }
    }
    return 0; // 정상종료
}