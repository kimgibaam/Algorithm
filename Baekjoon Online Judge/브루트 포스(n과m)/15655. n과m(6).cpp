#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
int arr[8];
vector<int> picked;

// 입력 받는 중복없는 조합
void solve(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
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
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0,0);

	return 0;
}