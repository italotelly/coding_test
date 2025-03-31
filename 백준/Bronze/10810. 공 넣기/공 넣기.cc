#include <iostream>

using namespace std;

// 공 넣기
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    /*
        N = 바구니 개수
        바구니에에 공을 1개씩 넣음

        M번 공을 넣으려할 때 한번 공을 넣을 때 바구니 범위를 정하고
        정한 바구니에 모두 같은 번호가 적혀있는 공을 넣음

        만약 바구니에 공이 이미 있는 경우 들어있는 공을 빼고 새로 공을 넣음
        공을 넣을 바구니는 연속

        공을 어떻게 넣을지가 주어졌을 때 M번 공을 넣은 이후 각 바구니에 어떤 공이
        들어 있는지 구하는 프로그램
    */

    int N, M;

    cin >> N >> M;
    if (N < 1 || N > 100 || M < 1 || M > 100)
    {
        return 1; // 비정상 종료
    }

    int arr[N] = {};
    int i, j, k;
    for (int a = 0; a < M; a++)
    {
        cin >> i >> j >> k;
        if (1 > i || i > j || j > N || 1 > k || k > N)
        {
            return 1; // 비정상 종료
        }
        for (i; i <= j; i++)
        {
            arr[i - 1] = k;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0; // 정상종료
}