#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

// 서로 다른 부분 문자열의 개수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    unordered_set<string> A;

    // 모든 부분 문자열을 set에 삽입
    for (int i = 0; i < s.size(); i++)
    {
        string sub = "";
        for (int j = i; j < s.size(); j++)
        {
            sub += s[j];   // 부분 문자열 생성
            A.insert(sub); // set에 삽입 (중복 방지)
        }
    }

    cout << A.size() << '\n'; // 서로 다른 부분 문자열 개수 출력

    return 0;
}