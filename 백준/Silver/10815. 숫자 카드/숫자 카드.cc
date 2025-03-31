#include <iostream>
#include <vector>
#include <algorithm> // 정렬 및 이진 탐색을 위한 헤더

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> v1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v1[i];
    }

    // 정렬 (O(N log N))
    sort(v1.begin(), v1.end());

    int M;
    cin >> M;

    int num;
    for (int i = 0; i < M; i++)
    {
        cin >> num;

        // 이진 탐색 (O(log N))
        if (binary_search(v1.begin(), v1.end(), num))
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }

    return 0;
}