#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<long long> distance;
	vector<long long> price;

	cin >> N;
	distance.resize(N - 1, 0);
	price.resize(N, 0);

	long long total = 0;
	long long low_price = 10000;

	for (int i = 0; i < distance.size(); i++) {
		cin >> distance[i];
	}

	for (int i = 0; i < price.size(); i++) {
		cin >> price[i];
		low_price = min(low_price, price[i]);
	}
	// 최소 기름으로 마지막까지 다 사고
	// 최소 기름 전까지는 낮은 가격으로 계속해서 chage하며 삼

	// 첫 기름은 무조건 다음 node까지 갈 수 있을 만큼

	int i = 0;
	while (i < distance.size()) {
		if (price[i] == low_price) {
			for (int j = i; j < distance.size(); j++) {
				total = total + price[i] * distance[j];
			}
			break;
		}
		else if (price[i] <= price[i+1]) {
			total = total + price[i] * distance[i];
			price[i + 1] = price[i];
			i++;
		}
		else {
			total = total + price[i] * distance[i];
			i++;
		}
	}

	cout << total;

	return 0;
}