#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> A;
vector<long long> B;
vector<long long> C;
vector<long long> D;

vector<long long> E;
vector<long long> F;

long long rst;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			E.push_back(A[i] + B[j]);
		}
	}

	for (int i = 0; i < C.size(); i++)
	{
		for (int j = 0; j < D.size(); j++)
		{
			F.push_back(C[i] + D[j]);
		}
	}

	sort(E.begin(), E.end());
	sort(F.begin(), F.end());

	int st = 0;
	int en = F.size() - 1;

	while (st < E.size() && en >= 0) {
		if (E[st] + F[en] > 0) en--;
		else if (E[st] + F[en] < 0) st++;
		else {
			long long e_val = E[st];
			long long f_val = F[en];
			long long cntE = 0;
			long long cntF = 0;

			while (st < (int)E.size() && E[st] == e_val) {
				cntE++;
				st++;
			}

			while (en >= 0 && F[en] == f_val) {
				cntF++;
				en--;
			}

			rst += cntE * cntF;
		}
	}

	cout << rst << "\n";

	return 0;
}