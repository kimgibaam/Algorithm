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
	if (prev_permutation(num.begin(), num.end()))
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
	else cout << "-1";
	return 0;
}