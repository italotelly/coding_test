#include <iostream>
#include <vector>

using namespace std;

// 대표값2

int selection_sort(vector<int> &v, int v_size)
{
    for (int i = 0; i < v_size - 1; i++)
    {
        int min_num = i;
        for (int j = i + 1; j < v_size; j++)
        {
            if (v[i] > v[j])
            {
                min_num = j;
                swap(v[i], v[min_num]);
            }
        }
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        v.push_back(num);
        sum += v[i];
    }

    selection_sort(v, v.size());
    int arg = sum / 5;

    cout << arg << "\n"
         << v[2];

    return 0; // 정상종료
}