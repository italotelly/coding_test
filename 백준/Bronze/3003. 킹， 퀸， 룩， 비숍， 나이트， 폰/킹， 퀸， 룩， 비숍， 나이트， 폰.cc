#include <iostream>

using namespace std;

// 킹. 퀸, 룩, 비숍, 나이트, 폰
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int chess[6] = {};
    int b_chess[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++)
    {
        cin >> chess[i];
        cout << b_chess[i] - chess[i] << " ";
    }

    return 0; // 정상종료
}