#include <iostream>
#include <vector>

using namespace std;

// 암호문2
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1차원 벡터
    vector<int> v;

    // 원본 암호문 길이
    int N;
    // 명령어의 개수
    int command;
    // 명령어
    char com;
    int x, y, s;

    // TC
    for (int i = 1; i <= 10; i++)
    {
        cin >> N;
        v.clear();
        v.resize(N);

        // 원본 암호문 삽입
        for (int j = 0; j < N; j++)
        {
            cin >> v[j];
        }

        // 명령어의 개수
        cin >> command;
        for (int j = 0; j < command; j++)
        {
            cin >> com;

            // insert
            if (com == 'I')
            {
                cin >> x >> y;
                for (int k = 0; k < y; k++)
                {
                    cin >> s;
                    v.insert(v.begin() + x + k, s);
                }
            }
            // delete
            else
            {
                cin >> x >> y;
                for (int k = 0; k < y; k++)
                {
                    v.erase(v.begin() + x);
                }
            }
        }
        // 출력
        cout << "#" << i << " ";
        for (int j = 0; j < 10; j++)
        {
            cout << v[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
