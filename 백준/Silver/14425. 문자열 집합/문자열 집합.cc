#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

// 문자열 집합
int main()
{
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);

    int N, M;

    cin >> N >> M;

    string word;

    unordered_set<string> s1;

    for (int i = 0; i < N; i++)
    {
        cin >> word;
        s1.insert(word);
    }
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> word;
        if (s1.find(word) != s1.end())
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}