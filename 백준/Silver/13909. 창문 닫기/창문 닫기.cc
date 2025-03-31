#include <iostream>
#include <vector>

using namespace std;

// 창문 닫기
int main()
{
    long long int N;

    cin >> N;
    int count = 0;

    // 약수의 개수가 홀수개 인 것 == 제곱수
    for (int i = 1; i * i < N + 1; i++)
    {
        count++;
    }

    cout << count;

    return 0;
}