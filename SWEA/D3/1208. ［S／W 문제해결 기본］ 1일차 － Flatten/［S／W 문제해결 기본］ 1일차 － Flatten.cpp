#include <iostream>
#include <map>

using namespace std;

// Flatten
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dump;
    int max_num;
    int min_num;
    int max_pos;
    int min_pos;

    multimap<int, int> m;
    for (int i = 1; i <= 10; i++)
    {
        m.clear();
        cin >> dump;

        // 상자의 높이 입력
        for (int j = 1; j <= 100; j++)
        {
            int num;
            cin >> num;
            m.insert({num, j});
        }
        // dump
        for (int j = 1; j <= dump; j++)
        {
            auto max_it = prev(m.end());
            auto min_it = m.begin();

            max_num = max_it->first;
            min_num = min_it->first;
            max_pos = max_it->second;
            min_pos = min_it->second;

            if (max_num - min_num <= 1)
                break;

            m.erase(max_it);                  // 최대값 하나 지우고
            m.erase(min_it);                  // 최소값 하나 지움
            m.insert({max_num - 1, max_pos}); // 한 칸 낮춰서 삽입
            m.insert({min_num + 1, min_pos}); // 한 칸 올려서 삽입
        }

        // 종료 후 마지막 높이 차이 계산
        auto max_it = prev(m.end());
        auto min_it = m.begin();
        cout << "#" << i << " " << max_it->first - min_it->first << "\n";
    }
    return 0;
}
