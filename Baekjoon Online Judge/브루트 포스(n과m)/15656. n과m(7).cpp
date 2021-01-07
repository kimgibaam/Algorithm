#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
int arr[8];
vector<int> picked;

// 입력이 있으며 중복이 가능한 순열
void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		picked.push_back(arr[i]);
		solve(cnt + 1);
		picked.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0);

	return 0;
}