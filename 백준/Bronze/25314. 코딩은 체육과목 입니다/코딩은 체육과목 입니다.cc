#include <iostream>

using namespace std;

// 코딩은 체육과목 입니다
int main()
{
    int N;
    cin >> N;

    if ( N < 4 || N > 1000 || N % 4 != 0)
    {
        return 1; // 비정상 종료
    }

    for (int i = 0; i < (N/4); i++){
        cout << "long ";
    }

    cout << "int";

    return 0; // 정상종료
}