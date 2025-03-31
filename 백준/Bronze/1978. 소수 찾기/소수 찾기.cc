#include <iostream>
#include <vector>

using namespace std;

// 소수 찾기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, k;
    vector<int> v;
    vector<int> w;
    int count = 0;

    cin >> N;

    // 소수란 1과 자기 자신만 약수로 갖는 수

    for (int i = 0; i < N; i++)
    {
        w.clear();
        cin >> k;
        v.push_back(k);
        for (int j = 1; j <= k; j++)
        {
            if (k % j == 0)
            {
                w.push_back(j);
            }
        }
        if (w.size() == 2)
        {
            count++;
        }
    }

    cout << count;

    return 0; // 정상종료
}