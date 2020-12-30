#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> num;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << num[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(num.begin(), num.end()));

	return 0;
}