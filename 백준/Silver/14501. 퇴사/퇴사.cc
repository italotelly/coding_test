#include <iostream>
#include <algorithm>

using namespace std;

int N;
int T[20];
int P[20];

int max_num;
int dp[20];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> P[i];
    }
    
    for (int i = N - 1; i >= 0; i--)
    {
        if(i + T[i] <= N) {
            dp[i] = P[i];
            for (int j = i + T[i]; j < N; j++)
            {
                dp[i] = max(dp[i], P[i] + dp[j]);   
            }
            dp[i] = max(dp[i], dp[i + 1]);
            max_num = max(max_num, dp[i]);
        }
        else {
            dp[i] = 0;
        }
    }
    
    cout << max_num << "\n";

    return 0;
}