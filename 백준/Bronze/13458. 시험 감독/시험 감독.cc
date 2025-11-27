#include <iostream>

using namespace std;

int N;
int A[1000005];
int B, C;

long long rst;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> B >> C;

    for (int i = 0; i < N; i++)
    {
        if(A[i] <= B) rst += 1;
        else if((A[i] - B) <= C) rst += 2;
        else if((A[i] - B) % C == 0) {
            rst += (A[i] - B) / C;
            rst++;
        }
        else {
            rst += ((A[i] - B) / C);
            rst += 2;
        }
    }
    
    cout << rst << "\n";

    return 0;
}