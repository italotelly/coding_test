#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 약수
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;

    vector<int> v;
    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cout << v.front() * v.back();

    return 0; // 정상종료
}