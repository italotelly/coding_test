#include <iostream>
#include <vector>

using namespace std;

// 크로아티아 알파벳
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<string> a;
    a.push_back("c=");
    a.push_back("c-");
    a.push_back("dz=");
    a.push_back("d-");
    a.push_back("lj");
    a.push_back("nj");
    a.push_back("s=");
    a.push_back("z=");

    string b;
    cin >> b;

    int wcnt = 0;
    // 최대 3번 test
    for (int i = 0; i < b.size(); i++)
    {
        int crotic = 0; // crotic word 찾을 시 1로 변함
        // d로 시작할 때만 3개 비교, 3개 비교 가능할 때
        if ((b[i] == 'd') && (i < (b.size() - 2)))
        {
            if (a[2] == b.substr(i, 3))
            {
                wcnt++;
                i += 2;
                continue;
            }
        }
        // else 2개 비교

        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == b.substr(i, 2))
            {
                wcnt++;
                i += 1;
                crotic = 1;
                break;
            }
        }
        if (crotic == 0)
        {
            wcnt++;
        }
    }

    cout << wcnt;

    return 0; // 정상종료
}