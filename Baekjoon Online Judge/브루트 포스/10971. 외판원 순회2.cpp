#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[10][10];
int n;
vector<int> picked;
int answer = 9999999999;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		picked.push_back(i);
	}

	do {
		bool flag = false;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[picked[i % n]][picked[(i + 1) % n]] == 0) {
				flag = true;
				break;
			}
			else {
				sum += arr[picked[i % n]][picked[(i + 1) % n]];
			}
		}
		if (flag == true) continue;
		if (answer > sum) answer = sum;

	} while (next_permutation(picked.begin(), picked.end()));

	cout << answer;

	return 0;
}