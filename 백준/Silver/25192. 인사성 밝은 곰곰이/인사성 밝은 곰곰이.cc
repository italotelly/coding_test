#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 인사성 밝은 곰곰이이
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string s;
    unordered_map<string, int> name;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s == "ENTER")
        {
            sum += name.size();
            name.clear();
            continue;
        }
        else
        {
            name.insert(pair<string, int>(s, 1));
        }
    }

    cout << sum + name.size();

    return 0; // 정상종료
}