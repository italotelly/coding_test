#include <iostream>
#include <deque>

using namespace std;

// querestack
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    int num;

    int ary[N];

    deque<int> dq;

    // queue 또는 stack 생성
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        ary[i] = num;
    }

    // queue 또는 stack에 값 삽입
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (ary[i] == 0)
        {
            dq.push_back(num);
        }
    }

    // X0 삽입
    int M;
    cin >> M;
    for (int j = 0; j < M; j++)
    {
        cin >> num;
        dq.push_front(num);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0; // 정상종료
}