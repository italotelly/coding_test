#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string input;
	cin >> input;

	vector<int> numbers;
	vector<char> operators;

	string num;
	for (char ch : input) {
		if (ch == '+' || ch == '-') {
			numbers.push_back(stoi(num));
			num = "";
			operators.push_back(ch);
		}
		else {
			num += ch;
		}
	}
	numbers.push_back(stoi(num));  // 마지막 숫자

	// 처음 숫자에서 시작
	int result = numbers[0];
	bool minus = false;

	for (int i = 0; i < operators.size(); ++i) {
		if (operators[i] == '-') {
			minus = true;
		}

		if (minus) {
			result -= numbers[i + 1];
		}
		else {
			result += numbers[i + 1];
		}
	}

	cout << result << endl;

	return 0;
}
