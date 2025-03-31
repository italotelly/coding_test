#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 붙임성 좋은 총총이
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string s1;
    string s2;
    unordered_map<string, int> name;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s1 >> s2;
        if (s1 == "ChongChong" || s2 == "ChongChong")
        {
            name.insert({s1, 1});
            name.insert({s2, 1});
        }
        else if (name.find(s1) != name.end())
        {
            name.insert({s2, 1});
        }
        else if (name.find(s2) != name.end())
        {
            name.insert({s1, 1});
        }
    }

    cout << name.size();

    return 0; // 정상종료
}