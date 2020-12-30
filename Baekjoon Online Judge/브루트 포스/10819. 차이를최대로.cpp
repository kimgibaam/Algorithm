#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> num;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	int answer = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(num[i] - num[i + 1]);
		}
		if (answer < sum) answer = sum;
	} while (next_permutation(num.begin(), num.end()));

	cout << answer;

	return 0;
}