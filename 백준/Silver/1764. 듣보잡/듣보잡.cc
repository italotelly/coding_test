#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

// 듣보잡
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    map<string, int> s;
    map<string, int>::iterator iter = s.begin();
    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        s[name] = 1;
    }
    int cnt = 0;

    for (int i = 0; i < M; i++)
    {
        cin >> name;
        if (s.find(name) != s.end())
        {
            cnt++;
            s[name]++;
        }
    }
    cout << cnt << "\n";
    for (iter = s.begin(); iter != s.end(); iter++)
    {
        if (iter->second == 2)
        {
            cout << iter->first << "\n";
        }
    }

    return 0;
}