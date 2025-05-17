#include <iostream>
#include <map>

using namespace std;

// 최빈수 구하기
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, tc;
    cin >> T;

    map<int, int> m;
    int num;

    for (int i = 1; i <= T; i++)
    {
        int max_cnt = 0;
        int max_num = 0;
        m.clear();

        cin >> tc;
        for (int j = 0; j < 1000; j++)
        {
            cin >> num;
            m[num]++;
            if (max_cnt < m[num])
            {
                max_cnt = m[num];
                max_num = num;
            }
            else if (max_cnt == m[num])
            {
                max_num = max(max_num, num);
            }
        }
        cout << "#" << tc << " " << max_num << "\n";
    }

    return 0;
}
