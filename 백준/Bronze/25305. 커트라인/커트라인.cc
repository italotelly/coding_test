#include <iostream>
#include <vector>

using namespace std;

// 커트라인

int insertion_sort(vector<int> &v, int v_size)
{
    for (int i = 1; i < v_size; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && (key < v[j]))
        {
            swap(v[j], v[j + 1]);
            j--;
        }
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, k;

    cin >> N >> k;

    vector<int> v;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    insertion_sort(v, v.size());

    cout << v[N - k];

    return 0; // 정상종료
}