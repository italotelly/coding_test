#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

int N;
long long min_sum = 1e18;

long long rst[3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        int st = i + 1;
        int en = N - 1;

        while(st < en){
            long long sum = v[i] + v[st] + v[en];

            if(abs(sum) < min_sum){
                rst[0] = v[i];
                rst[1] = v[st];
                rst[2] = v[en];
                min_sum = abs(sum);
            }
            if(sum > 0) en--;
            else st++;
        }
    }
 
    
    cout << rst[0] << " " << rst[1] << " " << rst[2] << "\n";
    

    return 0;
}
