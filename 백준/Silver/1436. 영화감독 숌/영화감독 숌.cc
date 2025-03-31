#include <iostream>
#include <string>

using namespace std;

// 영화감독 숌

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 666이 들어가는 수를 순서대로
    // 5666, 6660, 6661, 6662, 6663, 6664, ...

    int N;

    cin >> N;
    int count = 0;
    int num = 665;
    string s;
    while (N != count)
    {
        num++;
        s = to_string(num);
        if (s.find("666") != string::npos)
        {
            count++;
        }
    }

    cout << num;
    return 0; // 정상종료
}