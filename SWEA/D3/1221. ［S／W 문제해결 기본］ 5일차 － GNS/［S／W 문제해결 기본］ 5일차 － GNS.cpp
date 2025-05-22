#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int TC;

	cin >> TC;

	string k;
	int CT;
	string num;

	vector<string> v;
	v.push_back("ZRO");
	v.push_back("ONE");
	v.push_back("TWO");
	v.push_back("THR");
	v.push_back("FOR");
	v.push_back("FIV");
	v.push_back("SIX");
	v.push_back("SVN");
	v.push_back("EGT");
	v.push_back("NIN");

	for (int i = 1; i <= TC; i++) {	
		cin >> k;
		cin >> CT;
		int cnt_0 = 0;
		int cnt_1 = 0;
		int cnt_2 = 0;
		int cnt_3 = 0;
		int cnt_4 = 0;
		int cnt_5 = 0;
		int cnt_6 = 0;
		int cnt_7 = 0;
		int cnt_8 = 0;
		int cnt_9 = 0;

		for (int j = 0; j < CT; j++) {
			cin >> num;
			if (num == v[0]) {
				cnt_0++;
			}
			else if (num == v[1]) {
				cnt_1++;
			}
			else if (num == v[2]) {
				cnt_2++;
			}
			else if (num == v[3]) {
				cnt_3++;
			}
			else if (num == v[4]) {
				cnt_4++;
			}
			else if (num == v[5]) {
				cnt_5++;
			}
			else if (num == v[6]) {
				cnt_6++;
			}
			else if (num == v[7]) {
				cnt_7++;
			}
			else if (num == v[8]) {
				cnt_8++;
			}
			else if (num == v[9]) {
				cnt_9++;
			}
		}

		// 출력
		cout << "#" << i << " ";
		for (int j = 0; j < cnt_0; j++) {
			cout << "ZRO ";
		}
		for (int j = 0; j < cnt_1; j++) {
			cout << "ONE ";
		}
		for (int j = 0; j < cnt_2; j++) {
			cout << "TWO ";
		}
		for (int j = 0; j < cnt_3; j++) {
			cout << "THR ";
		}
		for (int j = 0; j < cnt_4; j++) {
			cout << "FOR ";
		}
		for (int j = 0; j < cnt_5; j++) {
			cout << "FIV ";
		}
		for (int j = 0; j < cnt_6; j++) {
			cout << "SIX ";
		}
		for (int j = 0; j < cnt_7; j++) {
			cout << "SVN ";
		}
		for (int j = 0; j < cnt_8; j++) {
			cout << "EGT ";
		}
		for (int j = 0; j < cnt_9; j++) {
			cout << "NIN ";
		}
		cout << "\n";
	}


	return 0;
}