#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[13];
int n;
vector<int> picked;

void solve(int cnt, int idx) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		picked.push_back(arr[i]);
		solve(cnt + 1, i + 1);
		picked.pop_back();
	}
}

int main() {
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		solve(0,0);
		cout << "\n";
	}

	return 0;
}