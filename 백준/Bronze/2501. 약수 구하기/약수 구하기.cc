#include <iostream>
#include <vector>

using namespace std;

// 약수 구하기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> v;

    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            v.push_back(i);
        }
    }

    if (v.size() < K)
    {
        cout << 0;
    }
    else
    {
        cout << v[K - 1];
    }
    return 0; // 정상종료
}