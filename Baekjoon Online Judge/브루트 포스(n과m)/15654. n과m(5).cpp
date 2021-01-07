#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
int arr[8];
int visited[8];
vector<int> picked;

// 자연수 입력을 직접 받음
void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 1) continue;
		picked.push_back(arr[i]);
		visited[i] = 1;
		solve(cnt + 1);
		picked.pop_back();
		visited[i] = 0;
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