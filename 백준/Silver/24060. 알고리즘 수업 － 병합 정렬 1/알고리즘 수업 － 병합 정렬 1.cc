#include <iostream>

using namespace std;

int chk = 0;
int count = 0;

void merge_sort(int A[], int b, int c, int &k);
void merge(int A[], int a, int b, int c, int &k);

void merge_sort(int A[], int p, int r, int &k)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q, k);
        merge_sort(A, q + 1, r, k);
        merge(A, p, q, r, k);
    }
}
void merge(int A[], int p, int q, int r, int &k)
{
    int i = p;
    int j = q + 1;
    int t = 0;
    int tmp[r - p + 1];
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[t++] = A[i++];
        }
        else
        {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q)
    {
        tmp[t++] = A[i++];
    }
    while (j <= r)
    {
        tmp[t++] = A[j++];
    }
    for (int a = 0; a < t; a++)
    {
        A[p + a] = tmp[a];
        count++;
        if (count == k)
        {
            chk = tmp[a];
        }
    }
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;

    int ary[N];

    for (int i = 0; i < N; i++)
    {
        cin >> ary[i];
    }

    merge_sort(ary, 0, sizeof(ary) / 4 - 1, K);

    if (chk == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << chk;
    }
    return 0;
}