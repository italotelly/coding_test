#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    // 누적합 배열: [알파벳][인덱스]
    vector<vector<int>> prefix(26, vector<int>(n + 1, 0));

    // 전처리: 각 문자의 누적합 계산
    for (int i = 0; i < n; ++i)
    {
        for (int ch = 0; ch < 26; ++ch)
        {
            prefix[ch][i + 1] = prefix[ch][i];
        }
        prefix[s[i] - 'a'][i + 1]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;

        int ch = a - 'a';
        // 누적합 이용해서 구간 내 개수 계산
        cout << prefix[ch][r + 1] - prefix[ch][l] << "\n";
    }

    return 0;
}
