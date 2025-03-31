#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second != b.second)  
        return a.second > b.second;  // 빈도순 정렬 (내림차순)
    if (a.first.size() != b.first.size())  
        return a.first.size() > b.first.size();  // 길이순 정렬 (내림차순)
    return a.first < b.first;  // 사전순 정렬 (오름차순)
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    string s;
    map<string, int> wordCount;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s.size() >= M)
        {
            wordCount[s]++;
        }
    }

    vector<pair<string, int>> words(wordCount.begin(), wordCount.end());

    sort(words.begin(), words.end(), compare);

    for (const auto &word : words)
    {
        cout << word.first << "\n";
    }
}
