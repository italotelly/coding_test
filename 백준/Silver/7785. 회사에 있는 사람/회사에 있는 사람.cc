#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

// 회사에 있는 사람
int main()
{
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);

    int n;

    set<string> s1;
    set<string>::reverse_iterator riter = s1.rbegin();

    string name;
    string eorl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> eorl;
        if (eorl == "enter")
        {
            s1.insert(name);
        }
        else if (eorl == "leave")
        {
            if (s1.find(name) != s1.end())
            {
                s1.erase(name);
            }
        }
    }

    for (riter = s1.rbegin(); riter != s1.rend(); riter++)
    {
        cout << *riter << "\n";
    }

    return 0;
}