#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 좌표 압축

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> ary(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ary[i];
    }

    // 1. 원본 배열 복사 후 정렬
    vector<int> sortedAry = ary;
    sort(sortedAry.begin(), sortedAry.end());

    // 2. 중복 제거
    sortedAry.erase(unique(sortedAry.begin(), sortedAry.end()), sortedAry.end());

    // 3. 좌표 압축 (lower_bound 활용)
    for (int i = 0; i < N; i++)
    {
        cout << lower_bound(sortedAry.begin(), sortedAry.end(), ary[i]) - sortedAry.begin() << " ";
    }
    return 0;
}