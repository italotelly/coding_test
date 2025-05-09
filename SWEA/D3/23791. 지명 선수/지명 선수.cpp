#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 지명선수
int main()
{
    // 1 ~ N명의 농구 선수
    // A, B 팀 N명 선수 순위 매김
    // A1 ~ AN, B1 ~ BN I번째로 선호하는 선수의 번호

    int T;

    cin >> T;

    int N; // 선수의 수
    map<int, int> a;
    map<int, int> b;
    int num;
    vector<char> c;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        a.clear();
        b.clear();
        c.resize(N, 0);
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            a.insert({num, j + 1});
        }
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            b.insert({num, j + 1});
        }
        // 각 팀이 가장 선호하는 선수
        for (int j = 0; j < N; j++)
        {
            // 팀 A 선발
            if (j % 2 == 0)
            {
                // 우선 순위가 가장 낮은 key값 find
                auto key = a.begin();
                for (auto it = a.begin(); it != a.end(); it++)
                {
                    if (key->second >= it->second)
                    {
                        key = it;
                    }
                }
                // 삽입
                c[key->first - 1] = 'A';
                // a 삭제
                a.erase(key->first);
                // b 삭제
                b.erase(key->first);
            }

            // 팀 B 선발
            else
            {
                // 우선 순위가 가장 낮은 key값 find
                auto key = b.begin();
                for (auto it = b.begin(); it != b.end(); it++)
                {
                    if (key->second >= it->second)
                    {
                        key = it;
                    }
                }
                // 삽입
                c[key->first - 1] = 'B';
                // a 삭제
                b.erase(key->first);
                // b 삭제
                a.erase(key->first);
            }
        }
        for (int j = 0; j < N; j++)
        {
            cout << c[j];
        }
        cout << "\n";
    }
    return 0;
}