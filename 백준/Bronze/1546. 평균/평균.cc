#include <iostream>
#include <algorithm>

using namespace std;

// 평균
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;

    cin >> N;
    if (N > 1000)
    {
        return 1; // 비정상 종료
    }

    double score[N] = {};

    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        if (score[i] < 0 || score[i] > 100)
        {
            return 1; // 비정상 종료
        }
    }

    double max_score = *max_element(score, score + N);
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        score[i] = (score[i] / max_score * 100);
        sum += score[i];
    }
    cout << sum / (double)N;

    return 0; // 정상종료
}