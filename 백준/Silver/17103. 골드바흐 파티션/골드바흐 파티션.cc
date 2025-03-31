#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;              // 최댓값 설정
vector<bool> is_prime(MAX_N + 1, true); // 소수 여부 저장
vector<int> primes;                     // 소수 목록 저장

// 에라토스테네스의 체: 미리 소수 계산
void sieve()
{
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수 아님
    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    // 소수 리스트 저장
    for (int i = 2; i <= MAX_N; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}

// 골드바흐 파티션 개수 계산
int goldbach_partition(int N)
{
    int partition = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] * 2 > N)
            break; // N보다 큰 수는 필요 없음
        if (is_prime[N - primes[i]])
            partition++;
    }
    return partition;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // 한 번만 수행하여 모든 소수를 구함

    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << goldbach_partition(N) << "\n";
    }

    return 0;
}